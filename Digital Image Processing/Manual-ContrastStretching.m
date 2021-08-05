Name = 'cameraman.png';
% Name = 'dog.jpg';
I = imread(Name);
if size(I, 3) == 3
    I = rgb2gray(I);
end

J = im2double(I);

A = double(min(min(I)));
B = double(max(max(I)));
D = B - A;
M = (2 ^ (floor(log2(double(B))) + 1)) - 1;

[row, col] = size(I);

for i = 1 : row
    for j = 1: col
        J(i, j) = ((double(I(i, j)) / D) * M) + A;
    end
end

J = uint8(J);

hist = zeros(1, M + 1);
for i = 1 : row
    for j = 1 : col
        hist(I(i, j) + 1) = hist(I(i, j) + 1) + 1;
    end
end

hist_new = zeros(1, M + 1);
for i = 1 : row
    for j = 1 : col
        hist_new(J(i, j) + 1) = hist_new(J(i, j) + 1) + 1;
    end
end

figure
subplot(2, 2, 1);
imshow(I);
title('Original Image');
subplot(2, 2, 2);
imshow(J);
title('Modified Image');

% figure
subplot(2, 2, 3);
bar(hist);
title('Original Image Histogram');
subplot(2, 2, 4);
bar(hist_new);
title('Modified Image Histogram');


stretched_Image = imadjust(I, stretchlim(I, [0.05, 0.95]),[]);

figure
subplot(2,2,1), imshow(I), title('Original Image');
subplot(2,2,2), imshow(stretched_Image), title('Strethced Image');
subplot(2,2,3), imhist(I), title('Histogram of Original Image');
subplot(2,2,4), imhist(stretched_Image), title('Histogram of Stretched Image');