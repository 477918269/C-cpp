void CreateGraph(AdjMatrix *G) //图的生成函数
{
	int n, e, vi, vj, w, i, j;
	printf("请输入图的顶点数和边数（以空格分隔）：");
	scanf("%d%d", &n, &e);
	G->numV = n; G->numE = e;
	for (i = 0; i<n; i++) //图的初始化
	for (j = 0; j<n; j++)
	{
		if (i == j)
			G->Edge[i][j] = 0;
		else
			G->Edge[i][j] = 32767;
	}
	for (i = 0; i<G->numV; i++) //将顶点存入数组中
	{
		printf("请输入第%d个顶点的信息:", i + 1);
		scanf("%d", &G->Vertices[i]);
	}
	printf("\n");

	for (i = 0; i<G->numE; i++)
	{
		printf("请输入边的信息i,j,w(以空格分隔):");
		scanf("%d%d%d", &vi, &vj, &w);
		//若为不带权值的图，则w输入1
		//若为带权值的图，则w输入对应权值

		G->Edge[vi - 1][vj - 1] = w;//①
		G->Edge[vj - 1][vi - 1] = w;//②
		//无向图具有对称性的规律，通过①②实现
		//有向图不具备此性质，所以只需要①
	}
}
