function hdl = display(u)
    [ny,nx] = size(u)
    hdl = figure()
    delmenu(hdl.figure_id,gettext("&File"))
    delmenu(hdl.figure_id,gettext("&Tools"))
    delmenu(hdl.figure_id,gettext("&Edit"))  
    delmenu(hdl.figure_id,gettext("&?"))   
    hdl.color_map = hsvcolormap(256)
    toolbar(hdl.figure_id,'off')
    hdl.axes_size = [nx,ny] 
    hdl.auto_resize = "off"
    ax_hdl = gca()
    ax_hdl.data_bounds = [1,1;nx,ny]
    ax_hdl.axes_visible = ["off","off","off"]
    ax_hdl.isoview = "on"
    ax_hdl.tight_limits = "on"
    ax_hdl.margins = [0,0,0,0]
    u(u~=0) = 1+modulo(u(u~=0)-1,256)
    Matplot(u)
endfunction

function clicker(u)
    hdl = display(u); 
    hdl.event_handler = "event_clicker";
    hdl.event_handler_enable = "on";
endfunction

function event_clicker(win, x, y, ibut)
    if ibut == 3 // left click detected
        printf("x=%d y=%d\n",x+1,y+1)
        close(scf(win))
    end
endfunction