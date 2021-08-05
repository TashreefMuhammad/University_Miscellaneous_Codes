%% Read and Resize Images
img1 = imread('input1.jpg');
img2 = imread('input2.jpg');

partition = 6;
factor = 100;
cusSze = partition * factor;
img1 = imresize(img1, [cusSze cusSze]);
img2 = imresize(img2, [cusSze cusSze]);
%% Display the Working Images
figure;
imshow(img1);
figure;
imshow(img2);
%% Construct and Display the Required New Image
outImg = img1;
for i = 2 : 2 : partition
    outImg(:, factor * (i - 1) + 1 : factor * i, :) = img2(:, factor * (i - 1) + 1 : factor * i, :);
end

figure;
imshow(outImg);
%% Save the New Image
imwrite(outImg, 'output.jpg');