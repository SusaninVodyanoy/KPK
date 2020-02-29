uses crt,graph;
var x0,y0,x1,y1,x2,y2,r,i:integer;
begin
x0:=0;
initgraph(x0,y0,'');
x0:=getmaxX div 2;
y0:=getmaxY div 2;
r:=150;
i:=1;
repeat
{координаты точек}
x1:=x0+round(r*sin(i*pi/180));
y1:=y0-round(r*cos(i*pi/180));
x2:=x0+round(r*sin(-i*pi/180));
y2:=y0-round(r*cos(-i*pi/180));
{рисуем цветом}
putpixel(x1,y1,12);
putpixel(x2,y2,14);
delay(50);{задержка}
{рисуем цветом фона=стираем}
putpixel(x1,y1,0);
putpixel(x2,y2,0);
i:=i+1;{увеличиваем угол на 1 градус}
if i>360 then i:=1;
until keypressed
end.
