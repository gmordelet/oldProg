function k = entierpp_seuille(x, n)
    k = max(min(round(x), n), 1);
endfunction

function J = interpolation_ppv(I, X, Y)
    
endfunction

I = read_bmp_bg('arbre1.bmp');
size(I)
cview(I,0);

I = niveau_gris(I); // version niveau de gris
[ny,nx] = size(I);
ny = size(I,1);
[X,Y] = meshgrid(-10:0.7:(nx+10),-10:0.9:(ny+10));