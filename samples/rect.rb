rectangles = proc do
  20.times do
    nostroke
    fill (0.6..1.0).rand, (0.1..1.0).rand, (0.2..1.0).rand, (0.4..1.0).rand
    r = rand(300) + 60
    rect (10..100).rand, (10..200).rand, r, r
  end
  button "OK", :left => 300, :top => 400 do
    clear &rectangles
  end
end

Shoes.app :width => 400, :height => 500, &rectangles
