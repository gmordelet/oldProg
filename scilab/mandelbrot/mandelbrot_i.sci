function mandelbrot_i(x0,y0,delta,R,N)
  u = mandelbrot(x0,y0,delta,R,N)
  hdl = display(u)
  hdl.user_data = [x0,y0,delta,R,N]
  hdl.event_handler = "event_mandelbrot_i";
  hdl.event_handler_enable = "on";	
endfunction

function event_mandelbrot_i(win,x,y,ibut)
  scf(win)
  hdl = gcf()
  str_id = sprintf("%d",hdl.figure_id)
  x0 = hdl.user_data(1);
  y0 = hdl.user_data(2);
  delta = hdl.user_data(3);
  R = hdl.user_data(4);
  N = hdl.user_data(5);
  redisplay = %F
  if ibut == 3 // clic gauche
    z = 4  // facteur de zoom
    x0 = x0+delta*(2*x/(R-1)-1)*(1-1/z); hdl.user_data(1) = x0;   
    y0 = y0-delta*(2*y/(R-1)-1)*(1-1/z); hdl.user_data(2) = y0;
    printf("zoom on (%.20f,%.20f) - delta = %e\n",x0,y0,delta)
    delta = delta/z; hdl.user_data(3) = delta;
    redisplay = %T
  elseif ibut == 61 // touche '+'
    N = N*2
    printf("N=%d\n",N)
    hdl.user_data(5) = N
    redisplay = %T
  elseif ibut == 45 // touche '-'
    N = int(N/2)+1
    printf("N=%d\n",N)
    hdl.user_data(5) = N
    redisplay = %T
  elseif ibut == 113 // touche 'q'
    close(hdl)
  end
  if redisplay
    u = mandelbrot(x0,y0,delta,R,N)
    Matplot(u)
  end
endfunction
