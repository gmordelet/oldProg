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

function event_clicker(win,x,y,ibut)
  if ibut == 3 // left click detected
    printf("x=%d y=%d\n",x+1,y+1)
    close(scf(win))
  end
endfunction

function zn = z(c ,n)
    zn = 0;
    for i = 0:n
        zn = zn * zn + c;
    end
endfunction

c = (2+%i)/10
z(c, 5)
z(c, 10)
z(c, 20)

c = 0.5+%i
z(c, 5)
z(c, 10)
z(c, 20)

function M = mandelbrot(x0, y0, delta, R, N)
    X = linspace(x0 - delta, x0 + delta, R);
    Y = linspace(y0 + delta, y0 - delta, R);
    C = ones(R, 1) * X + Y' * ones(1, R) * %i;
    Z = C;
    M = ones(C);
    for i = 2:N
        Z = Z .* Z + C;
        M(abs(Z) <= 2) = i;
    end
    M(M == N) = 0;
endfunction

//u = mandelbrot(-0.65,0,1.5,400,50);display(u);
//u = mandelbrot(-0.15,1.05,0.1,600,70);display(u);
//u = mandelbrot(-0.743,0.126,0.008,400,200);display(u);

function [x1,y1] = convert(x, y, x0, y0, delta, R)
    x1 = x0 - delta + x / R;
    y1 = y0 - delta + y / R;
endfunction

x0 = -0.65; y0 = 0; delta = 1.5; R = 400; N = 50;
u = mandelbrot(x0,y0,delta,R,N); clicker(u);

[x1, y1] = convert(381, 357, x0, y0, delta, R)


