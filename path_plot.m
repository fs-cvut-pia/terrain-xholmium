
function path_plot(terrain_file, path_file)
  
  terrain = load(terrain_file);
  path = load(path_file);
  
  
  width = 256;
  height = 256;

  % Create a visualization of the terrain
  [x_coords, y_coords] = meshgrid([1:width], [1:height]);
  fig = figure();
  ax = axes();
  terrain_plot = imshow(terrain,"displayrange",[-300,1600],"colormap",jet);
  hold on;
  contour(terrain,0:1,'k');

  % Load and plot file path.dat

  start = path(1,:);
  target = path(end,:);
  scatter([start(1), target(1)],[start(2),target(2)],200,[1 0 0],'+');

  plot(path(:,1),path(:,2),'r-',"linewidth",2);

  xlabel('X');
  ylabel('Y');

  colorbar();
