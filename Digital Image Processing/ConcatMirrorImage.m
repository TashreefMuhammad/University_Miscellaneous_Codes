%% Read Image
img = imread('input1.jpg');

%% Display the Working Images
figure;
imshow(img);

%% Construct Mirror Image
% img2 = flip(img1, 2);
% [row, col, dim] = size(img1);
% img2 = img1;
% for i = 1 : col
%     img2(:, i, :) = img1(:, end - i + 1, :);
% end
% 
% figure;
% imshow(img2);
%% Construct and Display the Required New Image
% outImg = [img1 img2];
outImg = [img img(:, end : -1 : 1, :)];

figure;
imshow(outImg);
%% Save the New Image
imwrite(outImg, 'output_OtherSet.jpg');