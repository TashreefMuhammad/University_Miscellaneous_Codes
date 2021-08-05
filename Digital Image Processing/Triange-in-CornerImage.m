%% Read Image
img = imread('new.jpg');

% figure;
% imshow(img);
%% 
[row1, col1, dim1] = size(img);
img = imresize(img, [500, 500]);
[row, col, dim] = size(img);
outImg1 = img;
greenImg = zeros(row, col, dim);
redImg = zeros(row, col, dim);
greenImg(:, :, 2) = 255.0;
redImg(:, :, 1) = 255.0;


for i = uint64(row / 2) : row
    for j = 1 : i - uint64(row / 2) + 1
        outImg1(i, j, :) = greenImg(i, j, :);
    end
end

for i = 1 : uint64(row / 2)
    for j = uint64(col / 2) + i : col
        outImg1(i, j, :) = redImg(i, j, :);
    end
end

outImg1 = imresize(outImg1, [row1, col1]);
% outImg2 = imresize(outImg2, [row1, col1]);

figure;
imshow(outImg1);

% figure;
% imshow(outImg2);
%% Save the New Image
imwrite(outImg1, 'output_GreenCorner.jpg');
% imwrite(outImg2, 'output_RedCorner.jpg');