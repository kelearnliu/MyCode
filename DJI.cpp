#include <iostream>
#include <string>
#include <utility>
#include <vector>

template <typename T>
void printVector(T& vec){
    for(auto t:vec)
    {
        std::cout << t << "\t";
    }
    std::cout << std::endl;
}

// �Զ���Ŀ¼���ڵ�ṹ
struct TreeNode {
    std::string name;
    std::vector<TreeNode*> children;
    TreeNode* parent;

    TreeNode(std::string n, TreeNode* p) : name(std::move(n)), parent(p) {}
};

// �ݹ齨��Ŀ¼��
void buildTree(TreeNode* node, int level, const std::vector<std::string>& lines) {
    while (level < lines.size()) {
        if (lines[level].find('-') == 0) {
            std::string name = lines[level].substr(lines[level].find_first_not_of('-'));
            auto *child = new TreeNode(name, node);
            node->children.push_back(child);
            buildTree(child, level + 1, lines);
        }
        ++level;
    }
}

// ��ȡ�Ӹ��ڵ㵽��ǰ�ڵ�ľ���·��
std::string getPath(TreeNode* node) {
    if (node->parent == nullptr) {
        return node->name;
    } else {
        return getPath(node->parent) + "/" + node->name;
    }
}

// �ݹ���������ָ�����ݵ��ļ���
void searchFiles(TreeNode* node, const std::string& target) {
    for (TreeNode* child : node->children) {
        if (child->name.find(target) != std::string::npos) {
            std::cout << "/" + getPath(child) << std::endl;
        }
        searchFiles(child, target);
    }
}

// �ݹ��ͷ�Ŀ¼���ڴ�
void deleteTree(TreeNode* node) {
    for (TreeNode* child : node->children) {
        deleteTree(child);
    }
    delete node;
}

void printNode(TreeNode* node) {
    std::cout << node->name << std::endl;
    for (TreeNode* child : node->children) {
        printNode(child);
    }
}

int main() {
    int n;
    std::cout << "Enter the number of lines: ";
    std::cin >> n;
    std::cin.ignore();  // ���Ի��з�

    std::vector<std::string> lines;
    for (int i = 0; i < n; ++i) {
        std::string line;
        std::getline(std::cin, line);
        lines.push_back(line);
    }
    printVector(lines);

    auto* root = new TreeNode("root", nullptr);
    buildTree(root, 0, lines);
    printNode(root);

    std::string target;
    std::cout << "Enter the target content to search for: ";
    std::getline(std::cin, target);

    std::cout << "Entries containing '" << target << "':" << std::endl;
    searchFiles(root, target);

    // �ͷ�Ŀ¼�����ڴ�
    deleteTree(root);

    return 0;
}
