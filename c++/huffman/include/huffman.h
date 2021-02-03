/**
 * huffman.h
 */
#ifndef _huffman_h
#define _huffman_h

#include <cstdlib>
#include <string>
#include <string.h>
#include <queue>
#include <map>
#include <fstream>

using namespace std;

#define MAX_SIZE 270
#define WRITE_BUFF_SIZE 10
#define PSEUDO_EOF 256

struct Huffman_node
{
    int id; 
    unsigned int freq;
    string code;
    Huffman_node  *left, 
                  *right,
                  *parent; 
};

typedef Huffman_node* Node_ptr;

class Huffman
{
private:
    Node_ptr node_array[MAX_SIZE]; // 叶子节点数组
    Node_ptr root;  // 根节点
    int size;  // 叶子节点数
    fstream in_file, out_file; // 输入、输出文件流
    map<int, string> table;  // 字符->huffman编码映射表

    class Compare
    {
        public:
            bool operator()(const Node_ptr& c1, const Node_ptr& c2) const
            {
                return (*c1).freq > (*c2).freq;
            }
    };

    // 用于比较优先队列中元素间的顺序
    priority_queue< Node_ptr, vector<Node_ptr>, Compare > pq;

    // 根据输入文件构造包含字符及其频率的数组
    void create_node_array();

    // 根据构造好的Huffman树建立Huffman映射表
    void create_map_table(const Node_ptr node, bool left);

    // 构造优先队列
    void create_pq();

    // 构造Huffman树
    void create_huffman_tree();

    // 计算Huffman编码
    void calculate_huffman_codes();

    // 开始压缩过程
    void do_compress();

    // 从huffman编码文件中重建huffman树
    void rebuid_huffman_tree();

    // 根据重建好的huffman树解码文件
    void decode_huffman();

public:
    // 根据输入和输出流初始化对象
    Huffman(string in_file_name, string out_file_name);

    // 析构函数
    ~Huffman();

    // 压缩文件
    void compress();

    // 解压文件
    void decompress();
};

#endif
