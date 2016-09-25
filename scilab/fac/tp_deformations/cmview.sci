//------------------------------ CMVIEW ------------------------------

// authors: Rémy Abergel, Lionel Moisan 
//
// display a sequence of gray-level images 
//
// usages: cmview(u);
//         cmview(u,framerate);
//         f = cmview(u [,framerate] );
//
// u is a hypermatrix, u(x,y,t) is the gray level of pixel (x,y) of frame t
// framerate: desired framerate (default value is 10)
// f: handle of the Scilab figure
//
// v1.0 (10/2012): initial version (RA)
// v1.1 (04/2013): removed format(4) (LM)


function fig_hdl = cmview (hypmat,fps)
  if argn(2)==1 fps = 10; end 
  
  //TODO: check types (uint8 hypermat & double) & Check third dimension > 1
  //...
  
  [height,width,ltime] = size(hypmat)
  
  //Skretching: rescale each frame to be into [0,255]
  for iter=1:ltime
    min_frame = min(hypmat(:,:,iter))
    max_frame = max(hypmat(:,:,iter))
    if (max_frame-min_frame)==0
      min_frame = 0 
      if ~max_frame
	max_frame = 1 
      end 
    end
    hypmat(:,:,iter) = 255*(hypmat(:,:,iter) - min_frame)/(max_frame-min_frame)
  end
  
  // Now let's build the image viewer
  fig_hdl = figure()
  delmenu(fig_hdl.figure_id,gettext("&File"))  //delete File menu (work for all languages)
  delmenu(fig_hdl.figure_id,gettext("&Tools")) //delete Tools menu
  delmenu(fig_hdl.figure_id,gettext("&Edit"))  //delete Edit menu
  delmenu(fig_hdl.figure_id,gettext("&?"))     //delete help menu
  str_id = string(fig_hdl.figure_id)
  fig_hdl.color_map = graycolormap(256) //set a linear gray colormap with 256 gray levels varying linearly from black to white
  fig_hdl.figure_name = "movie n°"+str_id
  toolbar(fig_hdl.figure_id,'off') //remove the toolbar
  fig_hdl.axes_size = [width,height] 
  fig_hdl.auto_resize = "off"
  
  fig_hdl.user_data = [0,0,fps,0,0] // = [quit,pause,fps,b,f] 
  // quit event = 0 as long as key 'q' is not pressed
  // pause event = 1 if key p is pressed, else 0
  // fps rate
  // backward event = 1 if key b is pressed, else 0
  // forward event  = 1 if key f is pressed, else 0
  
  ax_hdl = gca() //get current axes handle
  ax_hdl.data_bounds = [1,1;width,height]
  ax_hdl.axes_visible = ["off","off","off"]
  ax_hdl.isoview = "on"
  ax_hdl.tight_limits = "on" //axes will adapt in order to fit exactly with the data_bounds
  ax_hdl.margins = [0,0,0,0]
  
  // Now we can plot the first frame
  Matplot(hypmat(:,:,1))
  mtplt_hdl = gce()
  mtplt_hdl.user_data = ["Matplot",str_id] //Tag the Matplot entity
  fig_hdl.info_message = "# frame 1/" + string(ltime) + "  # fps (r/t) = " + string(1/fps) + "/" + string(fps)
  
  // Add an event handler function
  fig_hdl.event_handler = "event_cmview"
  fig_hdl.event_handler_enable = "on"
  
  // MAIN LOOP : Loop on frames
  usrdat = fig_hdl.user_data 
  count = 2 
  iter = 2 
  //format(4) 
  tref = 0 // tref = mean time needed to display a new frame
  
  while ~usrdat(1) // key 'q' has no been pressed (quit)
    
    tic // set clock to 0
    t1 = toc()
    
    // while t1< 1/fps - mean_time_to_display_the_new_frame, then display next frame.
    while t1<(1/usrdat(3)-tref)
      t1 = toc()
    end
    
    mtplt_hdl.data = hypmat(:,:,iter)
    t1 = toc() //real time that collapsed between frame iter-1 and frame iter
    
    //update info_message, tref & increment iter
    fig_hdl.info_message = "# frame "+string(iter) + "/" + string(ltime) + "  # fps (r/t) = " + string(1/t1) + "/" + string(usrdat(3))
    tref = ( tref*(count-1) + t1-1/usrdat(3)+tref ) / count // update tref => tref = mean(tref_iter=1,tref_iter=2,...,tref_iter, t1-(1/fps-tref_iter))
    usrdat = fig_hdl.user_data
    iter = modulo(iter,ltime) + 1 
    count = count + 1
    
    // check pause, Backard & Forward events
    while usrdat(2)&(~usrdat(1)) // key 'p' has been pressed and 'q' has not been pressed ==> pause 
      usrdat = fig_hdl.user_data
      fig_hdl.info_message = "# frame "+string(iter) + "/" + string(ltime)
      if usrdat(4) // key 'b' has been pressed
        iter = iter - 1 
	if iter<1 iter = ltime; end
        mtplt_hdl.data = hypmat(:,:,iter)
        fig_hdl.info_message = "# frame "+string(iter) + "/" + string(ltime)
        usrdat(4) = 0 
	fig_hdl.user_data = usrdat
      end
      if usrdat(5) //key 'f' has been pressed
        iter = modulo(iter,ltime) + 1
        mtplt_hdl.data = hypmat(:,:,iter)
        fig_hdl.info_message = "# frame "+string(iter) + "/" + string(ltime)
        usrdat(5) = 0 
	fig_hdl.user_data = usrdat
      end
    end
    
  end
  
  close(fig_hdl)
  // END MAIN LOOP
endfunction


function event_cmview(win,x,y,ibut)
  scf(win)
  fig_hdl = gcf()
  usrdat = fig_hdl.user_data
  usrdat(4) = 0 
  usrdat(5) = 0
  
  select ibut
    
  case -1000 then 
    if ~usrdat(1) 
      error("ERROR: Next time stop the movie by pressing key ''q''")
    end 
    usrdat(1) = 1 
  case 98 then // key 'b' has been pressed
    usrdat(4) = 1
  case 102 then // key 'f' has been pressed
    usrdat(5) = 1 
  case 108 then // key 'l' has been pressed
    usrdat(3) = usrdat(3) / 1.1
  case 109 then // key 'm' has been pressed
    usrdat(3) = 1.1 * usrdat(3)
  case 112 then // key 'p' has been pressed
    usrdat(2) = ~usrdat(2) 
  case 113 then // key 'q' has been pressed
    usrdat(1) = 1 
//    disp("Video has been stopped correctly")
  else
    break
  end
  
  fig_hdl.user_data = usrdat
endfunction

