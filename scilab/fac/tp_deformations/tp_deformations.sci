// Fonction niveau de gris

function J = niveau_gris(I)
    if length(size(I))==3 //3 canaux = image couleurs
        J = mean(I,3);
    else
        J = I;
    end
endfunction


// Calcule l'homographie qui transforme les 4 points
// (cx1(i),cy1(i)) i=1..4 en (cx2(i),cy2(i)) i=1..4,
// puis applique cette homographie aux points définis par
// les matrices x1 et y1 et retourne le résultat dans x2 et y2
// (matrices de même taille que x1 et y1)

function [x2,y2] = homographie(x1,y1,cx1,cy1,cx2,cy2)
  A = zeros(12,12)
  b = zeros(12,1)
  for i=1:4
    A(i*3  ,1) = cx1(i)
    A(i*3  ,2) = cy1(i)
    A(i*3  ,3) = 1
    A(i*3+1,4) = cx1(i)
    A(i*3+1,5) = cy1(i)
    A(i*3+1,6) = 1
    A(i*3+2,7) = cx1(i)
    A(i*3+2,8) = cy1(i)
    A(i*3  ,8+i) = -cx2(i)
    A(i*3+1,8+i) = -cy2(i)
    A(i*3+2,8+i) = -1
    b(i*3+2) = -1
  end
  p = linsolve(A,-b)
  D = p(7)*x1+p(8)*y1+ones(x1)
  x2 = (p(1)*x1+p(2)*y1+p(3)*ones(x1))./D
  y2 = (p(4)*x1+p(5)*y1+p(6)*ones(x1))./D
endfunction




////////////////////////////////////////////////////////////
// I) WARPING
////////////////////////////////////////////////////////////


// Fonction pour déterminer les coefficients d'une fonction interpolante obtenue par somme de fonctions de base radiale
function [alphai, ci] = solution_interp_surface(xi, yi, ai)
    // calcul des coefficients c
    n = size(xi,1);
    Xi = xi*ones(1,n);
    Yi = yi*ones(1,n);
    Ni = (Xi-Xi').^2 + (Yi-Yi').^2;
    ci = min(Ni+max(Ni)*eye(Ni),'c');
    Ci = ci*ones(1,n);
    M = (Ci' + Ni).^(-1/2);
    alphai = M\ai;
endfunction

// Calcul la fonction d'interpolation sur les coordonnées X, Y.
// X et Y peuvent être deux vecteurs ou deux matrices de même taille (données par un meshgrid par exemple).
function F = interp_surface(X, Y, xi, yi, ci, alphai)
    N = size(X(:),1);
    n = size(xi,1);
    Xi = xi*ones(1,N);
    Yi = yi*ones(1,N);
    Ci = ci*ones(1,N);
    VX = X(:)*ones(1,n);
    VY = Y(:)*ones(1,n);
    MRXY = (Ci' + (VX-Xi').^2 + (VY-Yi').^2).^(-1/2);
    F = MRXY*alphai;
    F = matrix(F, size(X));
endfunction


////////////////////////////////////////////////////////////
// Interpolation de champs de vecteurs
////////////////////////////////////////////////////////////

function [alphai, betai, ci] = solution_interp_champ(xi, yi, ai, bi)
    [alphai, ci] = solution_interp_surface(xi, yi, ai);
    [betai, ci] = solution_interp_surface(xi, yi, bi);
endfunction

//// Version simple de interp_champ :
//function [U1, U2]=interp_champ(X, Y, xi, yi, ci, alphai, betai)
//    U1 = interp_surface(X, Y, xi, yi, ci, alphai);
//    U2 = interp_surface(X, Y, xi, yi, ci, betai);
//endfunction

// interp_champ : code explicite pour limiter les calculs
function [U1, U2]=interp_champ(X, Y, xi, yi, ci, alphai, betai)
    N = size(X(:),1);
    n = size(xi,1);
    Xi = xi*ones(1,N);
    Yi = yi*ones(1,N);
    Ci = ci*ones(1,N);
    VX = X(:)*ones(1,n);
    VY = Y(:)*ones(1,n);
    MRXY = (Ci' + (VX-Xi').^2 + (VY-Yi').^2).^(-1/2);
    U1 = matrix(MRXY*alphai, size(X));
    U2 = matrix(MRXY*betai, size(X));
endfunction







