inline int read(int &x) { 
	char c;     
	while (c = getchar(), c<'0' || c>'9');x = c - '0';     
	while (c = getchar(), c >= '0'&&c <= '9')x = x * 10 + c - '0'; 
}