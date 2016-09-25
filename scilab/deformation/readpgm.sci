// lecture d'une image contenue dans un fichier PGM RAW (8 bits)
// exemple d'appel: u = readpgm('lena.pgm');

function image=readpgm(filename)
  function l=getline(u)
    h=[]
    while %t 
      c=mget(1,'uc',u)
      if c==10 then break,end
      h=[h c]
    end
    l=ascii(h)
  endfunction
  [u,err]=mopen(filename,'rb')
  if err<>0 then error('Impossible to open file '+filename), end
  if getline(u)~='P5' error('Unrecognized format'), end
  z=getline(u), while part(z,1)=='#', z=getline(u), end
  execstr('n=['+z+']')
  getline(u)
  image=matrix(mget(n(1)*n(2),'uc',u),n)
  mclose(u)
endfunction

