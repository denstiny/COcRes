#ifndef _CMAP_H_
#define _CMAP_H_


#include <iostream>
#include <vector>
#include <cstring>
#include <assert.h>
using namespace std;

//顶点
class Node
{
public:
	Node(char data = 0)
	{
		m_cData = data;
		m_bVisited = false;
	}
	Node(const Node& node)
	{
		if (this == &node)
			return;
		*this = node;
	}


	Node& operator=(const Node& node)
	{
		if (this == &node)
			return *this;
		this->m_cData = node.m_cData;
		this->m_bVisited = node.m_bVisited;
		return *this;
	}
public:
	char m_cData; //数据
	bool m_bVisited; //是否访问
};

//边
class Edge
{
public:
	Edge(int nodeIndexA = 0, int nodeIndexB = 0, int weightValue = 0) :
		m_iNodeIndexA(nodeIndexA),
		m_iNodeIndexB(nodeIndexB),
		m_iWeightValue(weightValue),
		m_bSelected(false) {}
	Edge(const Edge& edge)
	{
		if (this == &edge)
			return;
		*this = edge;
	}

	Edge& operator=(const Edge& edge)
	{
		if (this == &edge)
			return *this;
		this->m_iNodeIndexA = edge.m_iNodeIndexA;
		this->m_iNodeIndexB = edge.m_iNodeIndexB;
		this->m_iWeightValue = edge.m_iWeightValue;
		this->m_bSelected = edge.m_bSelected;
		return *this;
	}

public:
	int m_iNodeIndexA; //头顶点
	int m_iNodeIndexB; //尾顶点
	int m_iWeightValue; //权重
	bool m_bSelected; //是否被选中
};


	//图
class CMap
{

private:
	int m_iCapacity; //顶点总数
	int m_iNodeCount; //当前顶点数量
	Node *m_pNodeArray; //顶点集合
	int *m_pMatrix; //邻接距阵
	Edge *m_pEdgeArray; //最小生成树边集合
public:
	CMap(int iCapacity)
	{
		m_iCapacity = iCapacity;
		m_iNodeCount = 0;
		m_pNodeArray = new Node[m_iCapacity];
		m_pMatrix = new int[m_iCapacity*m_iCapacity];
		memset(m_pMatrix, 0, m_iCapacity*m_iCapacity * sizeof(int));
		m_pEdgeArray = new Edge[m_iCapacity - 1];
	}
	~CMap(void)
	{
		delete[]m_pNodeArray;
		delete[]m_pMatrix;
		delete[]m_pEdgeArray;
	}

private:
	//广度遍历具体实现
	void breadthFirstTraverseImpl(vector<int> preVec)
	{
		int val = 0;
		vector<int> curVec;
		for (int i = 0; i < (int)preVec.size(); i++)
		{
			for (int j = 0; j < m_iCapacity; j++)
			{
				getValueFromMatrix(preVec[i], j, val);
				if (/*1 == val*/0 != val)
				{
					if (m_pNodeArray[j].m_bVisited)
						continue;
					cout << m_pNodeArray[j].m_cData << " ";
					m_pNodeArray[j].m_bVisited = true;
					curVec.push_back(j);
				}
				else
					continue;
			}
		}

		if (curVec.empty())
			return;
		else
			breadthFirstTraverseImpl(curVec);
	}

	//取最小边
	int getMinEdge(const vector<Edge>& edgeVec)
	{
		int min = 0, minEdge = 0;

		for (int i = 0; i < (int)edgeVec.size(); i++)
		{
			if (edgeVec[i].m_bSelected)
				continue;
			min = edgeVec[i].m_iWeightValue;
			minEdge = i;
		}

		for (int i = 0; i < (int)edgeVec.size(); i++)
		{
			if (edgeVec[i].m_bSelected)
				continue;
			if (min > edgeVec[i].m_iWeightValue)
			{
				min = edgeVec[i].m_iWeightValue;
				minEdge = i;
			}
		}

		if (0 == min)
			return -1;

		return minEdge;
	}

	bool isInSet(const vector<int>& nodeSet, int target)
	{
		for (int i = 0; i < (int)nodeSet.size(); i++)
		{
			if (nodeSet[i] == target)
				return true;
		}

		return false;
	}

	void mergeNodeSet(vector<int>& nodeSetA, const vector<int>& nodeSetB)
	{
		for (size_t i = 0; i < (int)nodeSetB.size(); i++)
		{
			nodeSetA.push_back(nodeSetB[i]);
		}
	}
public:
	//添加顶点
	void addNode(Node *node)
	{
		assert(node);
		m_pNodeArray[m_iNodeCount].m_cData = node->m_cData;
		m_iNodeCount++;
	}
	//将顶点访问设置默认
	void resetNode()
	{
		for (int i = 0; i < m_iNodeCount; i++)
			m_pNodeArray[i].m_bVisited = false;
	}
	//设置权重-有向图
	bool setValueToMatrixForDirectedGraph(int row, int col, int val = 1)
	{
		if (row < 0 || row >= m_iCapacity)
			return false;
		if (col < 0 || col >= m_iCapacity)
			return false;
		m_pMatrix[row*m_iCapacity + col] = val;
		return true;
	}

	//设置权重-无向图
	bool setValueToMatrixForUndirectedGraph(int row, int col, int val = 1)
	{
		if (row < 0 || row >= m_iCapacity)
			return false;
		if (col < 0 || col >= m_iCapacity)
			return false;
		m_pMatrix[row*m_iCapacity + col] = val;
		m_pMatrix[col*m_iCapacity + row] = val;
		return true;
	}
	//获取权重
	bool getValueFromMatrix(int row, int col, int& val)
	{
		if (row < 0 || row >= m_iCapacity)
			return false;
		if (col < 0 || col >= m_iCapacity)
			return false;
		val = m_pMatrix[row*m_iCapacity + col];
		return true;
	}
	//打印矩阵
	void printMatrix()
	{
		for (int i = 0; i < m_iCapacity; i++)
		{
			for (int j = 0; j < m_iCapacity; j++)
				cout << m_pMatrix[i*m_iCapacity + j] << " ";
			cout << endl;
		}
	}

	//深度遍历
	void depthFirstTraverse(int index)
	{
		int val = 0;
		cout << m_pNodeArray[index].m_cData << " ";
		m_pNodeArray[index].m_bVisited = true;

		for (int i = 0; i < m_iCapacity; i++)
		{
			getValueFromMatrix(index, i, val);
			if (/*1 == val*/0 != val)
			{
				if (m_pNodeArray[i].m_bVisited)
					continue;
				depthFirstTraverse(i);
			}
			else
				continue;
		}
	}

	//广度遍历
	void breadthFirstTraverse(int index)
	{
		cout << m_pNodeArray[index].m_cData << " ";
		m_pNodeArray[index].m_bVisited = true;

		vector<int> curVec;
		curVec.push_back(index);

		breadthFirstTraverseImpl(curVec);
	}

	//求最小生成树-普里斯算法
	void primTree(int index)
	{
		int val = 0;
		int iEdgeCount = 0;
		vector<Edge> edgeVec;//待选边集合

		//从传入点开始找
		vector<int> nodeIndexVec;
		nodeIndexVec.push_back(index);

		//结束条件：边数=顶点数-1
		while (iEdgeCount < m_iCapacity - 1)
		{
			//查找传入点的符合要求（权重不为0且目的点没有被访问）边
			int row = nodeIndexVec.back();
			cout << m_pNodeArray[row].m_cData << endl;
			m_pNodeArray[row].m_bVisited = true;

			for (int i = 0; i < m_iCapacity; i++)
			{
				getValueFromMatrix(row, i, val);
				if (0 == val)
					continue;
				if (m_pNodeArray[i].m_bVisited)
					continue;
				Edge edge(row, i, val);
				edgeVec.push_back(edge);
			}

			//取出最小边
			int retIndex = getMinEdge(edgeVec);
			if (-1 != retIndex)
			{
				//存储选中边
				edgeVec[retIndex].m_bSelected = true;
				m_pEdgeArray[iEdgeCount] = edgeVec[retIndex];
				cout << m_pNodeArray[m_pEdgeArray[iEdgeCount].m_iNodeIndexA].m_cData << " - ";
				cout << m_pNodeArray[m_pEdgeArray[iEdgeCount].m_iNodeIndexB].m_cData << " (";
				cout << m_pEdgeArray[iEdgeCount].m_iWeightValue << ") " << endl;
				iEdgeCount++;

				int iNodeIndex = edgeVec[retIndex].m_iNodeIndexB;
				//设置点被访问
				m_pNodeArray[iNodeIndex].m_bVisited = true;
				//存入目的点递归查找
				nodeIndexVec.push_back(iNodeIndex);
			}
		}

	}

	//最小生成树-克鲁斯卡尔算法
	void kruskalTree()
	{
		int val = 0;
		int edgeCount = 0;

		//定义存放节点集合数组
		vector<vector<int> > nodeSets;

		//第一步、取出所有边
		vector<Edge> edgeVec;
		for (int i = 0; i < m_iCapacity; i++)
		{
			for (int j = i + 1; j < m_iCapacity; j++)
			{
				getValueFromMatrix(i, j, val);
				if (0 == val)
					continue;
				if (m_pNodeArray[i].m_bVisited)
					continue;
				Edge edge(i, j, val);
				edgeVec.push_back(edge);
			}
		}

		//第二步、从所有边中取出组成最小生成树的边
		//1、算法结束条件：边数=顶点数-1
		while (edgeCount < m_iCapacity - 1)
		{
			//2、从边集合中找出最小边
			int retIndex = getMinEdge(edgeVec);
			if (-1 != retIndex)
			{
				edgeVec[retIndex].m_bSelected = true;

				//3、找出最小边连接点
				int nodeAIndex = edgeVec[retIndex].m_iNodeIndexA;
				int nodeBIndex = edgeVec[retIndex].m_iNodeIndexB;

				//4、找出点所在集合
				bool nodeAInSet = false;
				bool nodeBInSet = false;
				int nodeAInSetLabel = -1;
				int nodeBInSetLabel = -1;

				for (int i = 0; i < (int)nodeSets.size(); i++)
				{
					nodeAInSet = isInSet(nodeSets[i], nodeAIndex);
					if (nodeAInSet)
						nodeAInSetLabel = i;
				}

				for (int i = 0; i < (int)nodeSets.size(); i++)
				{
					nodeBInSet = isInSet(nodeSets[i], nodeBIndex);
					if (nodeBInSet)
						nodeBInSetLabel = i;
				}

				//5、根据点集合的不同做不同处理
				if (nodeAInSetLabel == -1 && nodeBInSetLabel == -1)
				{
					vector<int> vec;
					vec.push_back(nodeAIndex);
					vec.push_back(nodeBIndex);
					nodeSets.push_back(vec);
				}
				else if (nodeAInSetLabel == -1 && nodeBInSetLabel != -1)
				{
					nodeSets[nodeBInSetLabel].push_back(nodeAIndex);
				}
				else if (nodeAInSetLabel != -1 && nodeBInSetLabel == -1)
				{
					nodeSets[nodeAInSetLabel].push_back(nodeBIndex);
				}
				else if (-1 != nodeAInSetLabel && -1 != nodeBInSetLabel && nodeAInSetLabel != nodeBInSetLabel)
				{
					//mergeNodeSet(nodeSets[nodeAInSetLabel], nodeSets[nodeBInSetLabel]);
					nodeSets[nodeAInSetLabel].insert(nodeSets[nodeAInSetLabel].end(),
						nodeSets[nodeBInSetLabel].begin(),
						nodeSets[nodeBInSetLabel].end());
					for (int k = nodeBInSetLabel; k < (int)nodeSets.size() - 1; k++)
					{
						nodeSets[k] = nodeSets[k + 1];
					}
				}
				else if (nodeAInSetLabel != -1 && nodeBInSetLabel != -1 && nodeAInSetLabel == nodeBInSetLabel)
				{
					continue;
				}

				m_pEdgeArray[edgeCount] = edgeVec[retIndex];
				edgeCount++;

				cout << m_pNodeArray[edgeVec[retIndex].m_iNodeIndexA].m_cData << " - ";
				cout << m_pNodeArray[edgeVec[retIndex].m_iNodeIndexB].m_cData << " (";
				cout << edgeVec[retIndex].m_iWeightValue << ") " << endl;
			}
		}
	}
};

#endif // !_CMAP_H_
