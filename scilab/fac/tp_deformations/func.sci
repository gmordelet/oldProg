function k = entierpp_seuille(x,n)
    k = max(min(round(x), n), 1)
endfunction

function J = interpolation_ppv(I,X,Y)
    [ny, nx] = size(I);
    RX = entierpp_seuille(X, nx)
    RY = entierpp_seuille(Y, ny)
    J = I((RX - 1) * ny + RY)
    J = matrix(J, size(X)) 
endfunction

function J = interpolation_bilineaire(I, X, Y)
    J00 = interpolation_ppv(I, X - 0.5, Y - 0.5)
    J01 = interpolation_ppv(I, X - 0.5, Y + 0.5)
    J10 = interpolation_ppv(I, X + 0.5, Y - 0.5)
    J11 = interpolation_ppv(I, X + 0.5, Y + 0.5)
    FX = X - floor(X)
    FY = Y - floor(Y)
    J = (1 - FX) .* ((1 - FY) .* J00 + FY .* J01) + FX .* ((1 - FY) .* J10 + FY .* J11)
endfunction

function J = interpolation_bilrgb(I, X, Y)
    J = zeros(size(X, 1), size(X, 2), 3);
    for i = 1:3
        J(:, :, i) = interpolation_bilineaire(I(:, :, i), X, Y)
    end
endfunction

I = read_bmp_bg('arbre1.bmp');
nx = size(I,2);
ny = size(I,1);
y = -10:0.9:(ny+10);
x = -10:0.7:(nx+10);
Y = y'*ones(x);
X = ones(y')*x;              
J = interpolation_bilrgb(I, X, Y);
cview(I, 0);
cview(J, 1);

getd('.');
// image satellite
u = readpgm("sat.pgm")';
cview(u,0);

// positions
xt = [800,500,1000,1000];
yt = [600,80,100,130];

R = 256 // taille x et y de chaque image
v = zeros(R,R);
cx1 = [1,R,R,1];
cy1 = [1,1,R,R];
[x,y] = meshgrid(1:R,1:R);
[X,Y] = homographie(x,y,cx1,cy1,xt,yt);
v = interpolation_bilineaire(u,X,Y);
cview(v,1);

// image satellite
u = readpgm("sat.pgm")';
cview(u,0);

// positions de dÃ©but et de fin
xt0 = [1117,1060,1107,1156];
yt0 = [111,65,20,66];
xt1 = [644,23,956,964];
yt1 = [1000,101,194,199];

n = 50  // nombre d'images
R = 256 // taille x et y de chaque image
v = zeros(R,R,n);
cx1 = [1,R,R,1];
cy1 = [1,1,R,R];
[x,y] = meshgrid(1:R,1:R);
for i=1:n
    cx2 = ((n-i)*xt0+(i-1)*xt1)/(n-1);
    cy2 = ((n-i)*yt0+(i-1)*yt1)/(n-1);
    [X,Y] = homographie(x,y,cx1,cy1,cx2,cy2);
    v(:,:,i) = interpolation_bilineaire(u,X,Y);
end
cmview(v,15); // cmview = visualisation de film

I = read_bmp_bg('arbre1.bmp');
size(I)
nx = size(I,2);
ny = size(I,1);
y = 1:ny;
x = 1:nx;
Y = y'*ones(x);
X = ones(y')*x;              

xdel(winsid());
r = 20; 
A = 10; 
snx = floor(nx/r);
sny = floor(ny/r);
U = A*(rand(sny,snx)>0.5);
V = A*(rand(sny,snx)>0.5);
NU = interpolation_bilineaire(U,X/r,Y/r);
NV = interpolation_bilineaire(V,X/r,Y/r);
J = interpolation_bilrgb(I,X+NU,Y+NV);
cview(I);
cview(J);

//
²