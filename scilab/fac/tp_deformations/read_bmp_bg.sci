function f = read_bmp_bg(filename)

// read_bmp - read BMP files
//
//   f = read_bmp(filename);
//
//   Read uncompressed 8bits (grayscale) or 24bits (color) uncompressed BMP files.
//
//   If filename does not finish by '.bmp', then this extension is added.
//   To convert into an uncompress .bmp (into a terminal)
//   convert image.jpg +matte +compress image.bmp
//
//   Copyright (c) 2010 Gabriel Peyre
//   Copyright (c) 2014 Bruno Galerne
//  'us'


if isempty( mtlb_strfind(filename, '.bmp') )
    filename = strcat( [filename '.bmp'] );
end

fid = mopen(filename, 'rb');
if fid<0
    error(['Cannot open ' filename '.']);
end
    

////
// File Header

// file type, 2c
filetype = myget(fid, 2,'uc');
//filetype = char(filetype); 
// overall size, 4c 
filesize = myget(fid, 1,'i');
// reserved
tmp = myget(fid, 1,'i');
// offset
offs = myget(fid, 1,'i');

////
// Image header

headersize = myget(fid, 1,'i');
width = abs(myget(fid, 1,'i'));
height = abs(myget(fid, 1,'i'));
nplanes = myget(fid, 1,'s');    // should be 1
colordepth = myget(fid, 1,'s');
ncol = ceil(colordepth/8);
compressiontype = myget(fid, 1,'i'); 
if compressiontype~=0
    mclose(fid);
    error('Only works for uncompressed BMP');
end
totalsize = myget(fid, 1,'i');
resolhori = myget(fid, 1,'i');
resolvert = myget(fid, 1,'i');
palettesize = myget(fid, 1,'i');
if palettesize~=0
    mclose(fid);
    error('Does not works for colrmap BPM');
end
paletteimpsize = myget(fid, 1,'i');

if ncol==1
    // BUG
    height = height+2;
end

//
linesize = ceil(ncol*width/4)*4;
f = myget(fid, linesize*height,'uc');
if modulo(ncol*width,4)==0
    indexes = 1:(ncol*width*height);
else
    indexes = kron(ones(1,height),1:(ncol*width)) +...
    kron(0:(height-1), linesize*ones(1,ncol*width));
end

f = matrix(f, [linesize height] );
f //= f(1:ncol*width,:);

if ncol>1
    f = matrix(f(indexes), [ncol, width, height]);
    g = zeros(height,width,ncol);
    for i=1:ncol
        g(:,:,i) = (squeeze(f(i,:,:)))';
    end
    f = g;
    f = f($:-1:1,:,$:-1:1);
else // grayscale case
    f = matrix(f(indexes), [width height]);
    f = f';
    f = f($:-1:1,:);
end

f = double(f);

mclose(fid);

if ncol==1
    // BUG
    f = f(3:$,:,:);
end

endfunction



function a = myget(fid, n, c)

a = mget(n,c,fid);

endfunction
