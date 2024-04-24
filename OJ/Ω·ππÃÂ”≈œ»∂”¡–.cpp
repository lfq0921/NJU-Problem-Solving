struct cmp
{
	bool operator () (point A, pointB)
	{
		return A.dis > B.dis;
	}
};//优先队列中存结构体 
