clear;

se = strel('disk', 30);
r = 680;
c = 742;
s = 150;
white = ones(r, c);

titles = {'Original', 'Binary Image', 'Palm', 'Fingers (Noisy)', ...
    'Fingers (Noiseless)', 'Number of Finger'};

fig = figure('WindowState','maximized');

for i = 1 : 5
    I = imread(strcat('f', int2str(i), '.png'));
    
    Images{1} = I;
    
    if size(I, 3) == 3
         I = rgb2gray(I);
    end
    
    % I = im2bw(I);
    I = imbinarize(I);
    % imwrite(I, strcat('f', int2str(i), '_Binarized.png'));
    
    Images{2} = I;
    
    Images{3} = imdilate(imerode(I, se), se);
    Images{4} = Images{2} - Images{3};
    Images{5} = imfill(bwareaopen(Images{4}, 1000), 'holes');
    [~, cnt] = bwlabel(Images{5});
    Images{6} = insertText(white, [(r / 2) - (s / 2), (c / 2) - s], ...
        int2str(cnt), 'FontSize', s, 'BoxOpacity', 0.0);
    
    for j = 1 : 6
        subplot(5, 6, (i - 1) * 6 + j);
        imshow(Images{j}); title(titles{j});
    end
end
saveas(fig, 'output', 'jpg');
clc;
