int x;
int f(int x, int y){
	int x;
	{
		int x,y;
		x+y;
		{
			int x,z;
			x+y+z;
		}
	}
	{
		int w;
		x+y+w;	
	}
	x+y;
}
int g(int y){
	int z;
	f(x,y);
	g(z);
}

