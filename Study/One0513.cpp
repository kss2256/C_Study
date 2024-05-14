#include <string>
#include <vector>
#include <sstream>
#include <regex>


using namespace std;


/*
���� ����
���ϸ� ����
�� ������ �ڵ� �׽�Ʈ�� �� ������ �����̶�� �⳪�� ����ε� ��ä�� ������ ����� 
īī���� �Ի��� ������ ���� ����� ���� ������ �ð� �Ǿ���.
����� �������� ���α׷��� ���� ������ ��� ��� �־�, �̸� ������ ���ĵ� ���� ����� ���Ⱑ �����ߴ�. 
������ �̸� ������ �����ϸ� ���߿� ������� ver-10.zip�� ver-9.zip���� ���� ǥ�õǱ� �����̴�.
���� ��ȣ �ܿ��� ���ڰ� ���Ե� ���� ����� ���� �鿡�� �����ϱ� �����ߴ�. 
������ ���� ����� ["img12.png", "img10.png", "img2.png", "img1.png"]�� ���, 
�Ϲ����� ������ ["img1.png", "img10.png", "img12.png", "img2.png"] ���� ������, 
���� ������ ���ĵ� ["img1.png", "img2.png", "img10.png", img12.png"] ���� �ξ� �ڿ�������.
������ �ܼ��� ���� �ڵ� ���� �ƴ�, ���ϸ� ���Ե� ���ڸ� �ݿ��� ���� ����� ����� ���� ���α׷��� �����ϱ�� �ߴ�.
�ҽ� ���� ����ҿ� ����� ���ϸ��� 100 ���� �̳���, ���� ��ҹ���, ����, ����(" "), ��ħǥ("."), ���� ��ȣ("-")������
�̷���� �ִ�. ���ϸ��� �����ڷ� �����ϸ�, ���ڸ� �ϳ� �̻� �����ϰ� �ִ�.
���ϸ��� ũ�� HEAD, NUMBER, TAIL�� �� �κ����� �����ȴ�.
HEAD�� ���ڰ� �ƴ� ���ڷ� �̷���� ������, �ּ��� �� ���� �̻��̴�.
NUMBER�� �� ���ڿ��� �ִ� �ټ� ���� ������ ���ӵ� ���ڷ� �̷���� ������, ���ʿ� 0�� �� �� �ִ�. 
0���� 99999 ������ ���ڷ�, 00000�̳� 0101 � �����ϴ�.
TAIL�� �� ������ �κ�����, ���⿡�� ���ڰ� �ٽ� ��Ÿ�� ���� ������, �ƹ� ���ڵ� ���� �� �ִ�.
���ϸ�	HEAD	NUMBER	TAIL
foo9.txt	foo	9	.txt
foo010bar020.zip	foo	010	bar020.zip
F-15	F-	15	(�� ���ڿ�)
���ϸ��� �� �κ����� ���� ��, ���� ���ؿ� ���� ���ϸ��� �����Ѵ�.

���ϸ��� �켱 HEAD �κ��� �������� ���� ������ �����Ѵ�. �̶�, ���ڿ� �� �� ��ҹ��� ������ ���� �ʴ´�. 
MUZI�� muzi, MuZi�� ���� �ÿ� ���� ������ ��޵ȴ�.
���ϸ��� HEAD �κ��� ��ҹ��� ���� �ܿ��� ���� ���, NUMBER�� ���� ������ �����Ѵ�. 
9 < 10 < 0011 < 012 < 13 < 014 ������ ���ĵȴ�. ���� ���� 0�� ���õǸ�, 012�� 12�� 
���� �ÿ� ���� ���� ������ ó���ȴ�.
�� ������ HEAD �κа�, NUMBER�� ���ڵ� ���� ���, ���� �Է¿� �־��� ������ �����Ѵ�. 
MUZI01.zip�� muzi1.png�� �Է����� ������, ���� �Ŀ��� �Է� �� �־��� �� ������ ������ �ٲ��� �� �ȴ�.
������ ���� ���ϸ� ���� ���α׷��� �����϶�.
*/


//["img12.png", "img10.png", "img02.png", "img1.png", "IMG01.GIF", "img2.JPG"]
//["img1.png", "IMG01.GIF", "img02.png", "img2.JPG", "img10.png", "img12.png"]

vector<string> solution(vector<string> files) 
{
    vector<string> answer;
    //���� ǥ�����̶�°ɷ� ���� ���ڵ��� �˻��ϰų� ��ü�ϴ� �� ��� �ȴٰ� �Ѵ�.


    regex re("([a-zA-Z]+)(\\d+)(\\..*)");

    std::smatch match;
    std::regex_search(files[0], match, re);

    std::string prefix = match[1];
    std::string number = match[2];
    std::string extension = match[3];;

    for (int i = 0; i < files.size(); ++i)
    {
        istringstream timeToint(files[i]);
        string prefix, number, extension;

        std::getline(timeToint, prefix, '1'); // "img"
        std::getline(timeToint, number, '.'); // "12"
        std::getline(timeToint, extension);    // ".png"

    }

   



    return answer;
}



int main()
{
    vector<string> result;


    result = solution({ "img12.png", "img10.png", "img02.png", "img1.png", "IMG01.GIF", "img2.JPG" });



    return 0;
}