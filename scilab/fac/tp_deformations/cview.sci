//*********************** cview ***********************//
// authors: Rémy Abergel, Lionel Moisan (Bruno Galerne)
//* Visualiseur d'images couleur
//* 
//*   - rgb : hypermatrix representation of a RGB image
//*           rgb(:,:,1) = red channel,
//*           rgb(:,:,2) = green channel,
//*           rgb(:,:,3) = blue channel.
//* 
//*
function cview(rgb, scfnumber)

    if length(size(rgb)) == 2 // niveau de gris, on réplique la matrice sur 3 canaux RGB
        rgb = repmat(rgb,[1,1,3]);
    end
    [ny,nx,nc] = size(rgb);


    //* detect data type *//
    select typeof(rgb(1))
    case 'uint8'
        Max = 2 ^ 8 - 1;
        colorMap = double(matrix(rgb,nx*ny,nc)) / Max;
    case 'uint16'
        Max = 2 ^ 16 - 1;
        colorMap = double(matrix(rgb,nx*ny,nc)) / Max;
    case 'uint32'
        Max = 2 ^ 32 - 1;
        colorMap = double(matrix(rgb,nx*ny,nc)) / Max;
    else 
        disp("WARNING, input has been converted into integer (uint8 precision) "); 
        Max = 2 ^ 8 - 1;
        rgb = uint8(rgb);
        colorMap = double(matrix(rgb,nx*ny,nc)) / Max; 
    end

    //* create color index *//
    id = matrix(1:nx*ny,ny,nx);

    //* Now let's build the image viewer *//
    [lhs,rhs]=argn(0);
    if rhs>1
        fig_hdl = figure(scfnumber);
    else
        fig_hdl = figure(); 
    end
    delmenu(fig_hdl.figure_id,gettext("&File"));  // delete File menu (work for all languages)
    delmenu(fig_hdl.figure_id,gettext("&Tools")); // delete Tools menu
    delmenu(fig_hdl.figure_id,gettext("&Edit"));  // delete Edit menu
    delmenu(fig_hdl.figure_id,gettext("&?"));     // delete help menu
    str_id = sprintf("%d",fig_hdl.figure_id);
    fig_hdl.color_map = colorMap;
    fig_hdl.figure_name = "ccview n°"+str_id;
    toolbar(fig_hdl.figure_id,'off'); 
    fig_hdl.axes_size = [nx,ny]; 
    fig_hdl.auto_resize = "off";
    ax_hdl=gca();
    ax_hdl.data_bounds = [1,1;nx,ny];
    ax_hdl.axes_visible = ["off","off","off"];
    ax_hdl.isoview = "on";
    ax_hdl.tight_limits = "on"; 
    ax_hdl.margins = [0,0,0,0];

    //* now we can plot the image *//  
    Matplot(id);

    //* add an event handler function *//
    fig_hdl.event_handler = "event_cview"
    fig_hdl.event_handler_enable = "on";	

endfunction

function event_cview(win,x,y,ibut)
  scf(win);
  fig_hdl = gcf();
  //str_id = sprintf("%d",fig_hdl.figure_id);
  //pixmap = fig_hdl.children.children.data; 
//  fig_hdl.info_message = sprintf("(x=%d,y=%d) : couleur = [%d, %d, %d]",x+1,y,...
//        uint8(255*fig_hdl.color_map(pixmap(y+1,x+1))),...
//        uint8(255*fig_hdl.color_map(pixmap(y+1,x+1)+length(fig_hdl.color_map)/3)),...
//        uint8(255*fig_hdl.color_map(pixmap(y+1,x+1)+2*length(fig_hdl.color_map)/3)));
//  fig_hdl.info_message = sprintf("(x=%d,y=%d) : (i=%d,j=%d) : value = ",x,y,y+1,x+1) + string(pixmap(y+1,x+1)); 
  if ibut == 113 then //key 'q' has been pressed
    close (fig_hdl);
  end
endfunction

function V=stretch(U)
    // stretch the values of U with the affine change of contraste [min U, max U] -> [0,255]
    m = min(U);
    M = max(U);
    if m==M then
        V = zeros(U);
    else
        V = 255*(U-m)/(M-m);        
    end

endfunction

