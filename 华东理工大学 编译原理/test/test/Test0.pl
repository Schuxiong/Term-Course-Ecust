const c1=2,c2=4;
var x,num,sum;
procedure func1;
var y;
y:=c1;
begin
  sum:=0;
  read(x);
  num:=10-x/c2;
  if num<-2 then
	x:=-c1;
  if num>2+2*c2 then
	x:=8-c2;
	while x<num do
		begin
			sum:=sum+x*x;
			x:=x+2;
		end;
	call func1;
	sum:=-10*c2/(2*sum+num);
	write(num,sum);
	;
end.
