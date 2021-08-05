img = imread('new.jpg');

[row1, col1, dim1] = size(img);
img = imresize(img, [2500, 2500]);
[row, col, dim] = size(img);

outImg = img;
r = 1000;
mid = 1250;
blueImg = zeros(row, col, dim);
blueImg(:, :, 3) = 255.0;

for i = 1 : row
    for j = 1 : col
        if (i - mid)^2 + (j - mid)^2 <= r^2
            outImg(i, j, :) = blueImg(i, j, :);
        end
    end
end

outImg = imresize(outImg, [row1, col1]);

imwrite(outImg, 'output_circle.jpg');