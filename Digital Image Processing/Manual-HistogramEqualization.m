Name = 'cameraman.png';
% Name = 'dog.jpg';
I = imread(Name);
if size(I, 3) == 3
    I = rgb2gray(I);
end
J = I;

B = max(max(I));
[row, col] = size(I);
L = 2 ^ (floor(log2(double(B))) + 1);

hist = zeros(1, L);
CDF = zeros(1, L);

for i = 1 : row
    for j = 1 : col
        hist(I(i, j) + 1) = hist(I(i, j) + 1) + 1;
    end
end

PDF = hist / sum(hist);

CDF(1) = PDF(1);
for i = 2 : L
    CDF(i) = PDF(i) + CDF(i - 1);
end

CDF = round(CDF * (L - 1));

for i = 1 : row
    for j = 1 : col
        J(i, j) = CDF(I(i, j) + 1);
    end
end

hist_new = zeros(1, L);
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