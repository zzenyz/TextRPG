#include "Ending.h"
void BadEndingSequence()
{
    ClearScreen();

    // �󰡿��� ���� ����
    TypeWriter("[�� ��]\n", 30);
    TypeWriter("������ ����� �����Ѵ�. �󱼿��� �ȵ����� �����ϴ�.\n", 40);
    TypeWriter("\"��ȥ���� ��� ���� �� ����. ���� ������ �ذ�� ���ϰ�.\"\n", 50);
    TypeWriter("\"������ ������ ���Ƶ� �� �ž�.\"\n\n", 50);

    TypeWriter("������ ����� ���� ������ ������ ������ �ʴ�.\n", 40);
    TypeWriter("���� ������ �� ���� �Ҿ��� �з�����, �߿��� ���𰡸� ��ģ ���� ����� ���.\n\n", 50);

    TypeWriter("--- [����Ϸ��� Enter] ---\n", 30);
    std::cin.get();
    ClearScreen();

    // ������ ���ư�
    TypeWriter("������ ���ƿ�����, ����� ������ ���̴�.\n", 40);
    TypeWriter("�� �� ������ ����� �ܻ��� ������, �������� �ü��� ��������.\n", 50);
    TypeWriter("�߿��� ���𰡸� ���� ���� �Ҿ��� �������� �İ���.\n\n", 50);

    TypeWriter("[1] �Ҿ��� ��ġ�� ���ڸ��� ���.\n", 30);
    TypeWriter("[2] �� ���� ������ ����.\n", 30);

    int choice = 0;
    while (true) {
        std::cout << "�������� �Է��ϼ��� (1 �Ǵ� 2): ";
        std::cin >> choice;

        if (choice == 1 || choice == 2) break;
        std::cout << "�ùٸ� �������� �Է��ϼ���.\n";
    }

    ClearScreen();

    switch (choice) {
    case 1:
        BadEnding_Sleep();
        break;
    case 2:
        BadEnding_Investigate();
        break;
    }
}

void BadEnding_Sleep()
{
    ClearScreen();

    TypeWriter("�Ҿ��� ������ �ﴩ���� ���ڸ��� �������,\n", 40);
    TypeWriter("���� ���� ã�ƿ��� �ʾҴ�.\n", 40);
    TypeWriter("�޼ӿ��� ��ȥ���� ������ �ӻ����� ���� ���������.\n", 50);

    SetConsoleColor(12);
    TypeWriter("\"��� �װ� ���ƿԱ�����\"\n", 70);
    TypeWriter("\"������ ���� �����̴١�\"\n\n", 70);
    SetConsoleColor(7);

    TypeWriter("��� �ӿ��� ��ü���� ������ ����� �巯����, ����� ���� �ٰ��´�.\n", 50);
    TypeWriter("������ ������ ��������, ���� ���ǰ� ���� ��谡 ��������.\n", 50);

    SetConsoleColor(12);
    TypeWriter("\"������! �����İ�! �̰� ��ü ����!\"\n", 80);
    TypeWriter("����� ����� ����� �޾Ƹ�ġ��, ���Ĺ��� ������ ȥ�� ������ �������.\n\n", 70);
    SetConsoleColor(7);

    TypeWriter("������� �ᱹ ������ ���⿡ �������� ����.\n\n", 70);

    SetConsoleColor(12);
    TypeWriter("--- [��忣��] ---\n", 50);
    TypeWriter("����� �̾߱�� ���⼭ �����.\n\n", 50);
    TypeWriter("--- [���� ����] ---\n", 40);
    SetConsoleColor(7);

    std::cin.get();
    ClearScreen();
}

void BadEnding_Investigate()
{
    ClearScreen();

    TypeWriter("�ұ��� �� ������� ������ ���Ǵ� ���,\n", 40);
    TypeWriter("������ ���ڱ��� ���� �ְ�, ��� �ӿ��� ���𰡰� ���Ѻ��� �ִ�.\n", 50);

    SetConsoleColor(12);
    TypeWriter("\"�װ��� �ٷ� �� �ڿ�������\"\n", 70);
    TypeWriter("\"������ �ݵ�� �̷���� ���̴١�\"\n\n", 70);
    SetConsoleColor(7);

    TypeWriter("�� �ڿ��� �������� ������ �ձ濡 ���� ���ٰ�,\n", 50);
    TypeWriter("���� ������ ������ ������ ���ƸԴ´�.\n", 50);

    SetConsoleColor(12);
    TypeWriter("\"������! ���� ����!!!\"\n", 80);
    TypeWriter("����� ���Ĺ��� �� ����� ������, ������ ������� ����.\n\n", 70);
    SetConsoleColor(7);

    TypeWriter("��ȥ���� ���� ���������, �ᱹ ����� ���� �ӿ� ��������.\n\n", 60);

    SetConsoleColor(12);
    TypeWriter("End.\n", 100);
    TypeWriter("- Ignorance Was Never Innocent -\n\n", 100);
    SetConsoleColor(7);

    TypeWriter("�����ߴ� ����� �ᱹ �밡�� ġ���� �Ǿ���.\n", 50);
    TypeWriter("�𸣴� �͵��� �˿���.\n\n", 50);
    TypeWriter("--- [���� ����] ---\n", 40);

    std::cin.get();
    ClearScreen();
}

void HappyEnding()
{
    ClearScreen();

    TypeWriter("������ ��ȥ���� ������, ����� �Ѱ� ����������.\n", 40);
    TypeWriter("����� ���� ���� ������ ���� ���� �������� ���� ��ȭ�� ������.\n", 50);
    TypeWriter("��� ���� ��Ŵ� ������ ������ ���� ������ ������.\n\n", 50);

    TypeWriter("�ָ��� ������ �ٰ��� ���Ѵ�.\n", 40);
    SetConsoleColor(11);
    TypeWriter("\"���� ������, �����Ե� ��� ������ ������ ã�� �� ������.\"\n\n", 60);
    SetConsoleColor(7);

    TypeWriter("������ ���� �� �� ���, ���� �ذ����� ���� ���𰡰� ���� ������ ������.\n", 50);
    TypeWriter("�׷����� �����δ� �� ���� ���� ��ƾ� �Ѵٴ� ������ �����.\n\n", 50);

    TypeWriter("���׸��� ����� ������ ���� �����̸� ���ο� ������ �����Ѵ�.\n\n", 60);

    SetConsoleColor(14);
    TypeWriter("End.\n", 100);
    TypeWriter("- Rebirth -\n\n", 100);
    SetConsoleColor(7);

    TypeWriter("��� ���� �ǵ������� ��������, ����� ���� ���θ� ������� ���ߴ�.\n", 50);
    TypeWriter("�׷��� ���� ��򰡿� ���� ������ ��å���� ����� ������ �̲���.\n", 50);
    TypeWriter("������ ����, �ٽô� ���� �Ǽ��� �������� �ʱ⸦ �ٶ�� ��ư� ���̴�.\n\n", 50);

    TypeWriter("--- [���� ����] ---\n", 40);

    std::cin.get();
    ClearScreen();
}

void BadEnding2()
{
    ClearScreen();

    SetConsoleColor(12);
    TypeWriter("��� ������ �巯�� ����,\n", 50);
    TypeWriter("������ ����� ����� �����Ѵ�.\n", 50);
    TypeWriter("ó������ �̼��� �ӻ��� ��������,\n", 50);
    TypeWriter("�̳� �� �Ҹ��� ���� Ŀ��, �Ӹ����� ������´�.\n\n", 70);

    TypeWriter("���� ���� ���ſ�����, ���� ������.\n", 50);
    TypeWriter("�ճ��� �δ��ϰ� �ľ��, ������ ������ �¸��� ���Ѵ�.\n", 50);
    TypeWriter("����� ���� �ӿ��� �ڷ� �������� ������,\n", 50);
    TypeWriter("�߰����� ���̰� ���� �پ� �������� �ʴ´�.\n\n", 70);

    TypeWriter("��ȥ���� �г밡 �ѵ� �� �Ŵ��� �׸��ڰ� �Ǿ� ����� ��ģ��.\n", 50);
    TypeWriter("�� ����� ���ں��ϰ� ����� �����Ű��,\n", 50);
    TypeWriter("������ �ǽĸ��� ����� ä, ����� ������ ����� ����.\n\n", 70);

    TypeWriter("���� ��, �󰡿��� ������ �ٶ����� �����ϰ� �帥��.\n", 50);
    TypeWriter("�� ��𿡵� ����� ������ ���� ���� �ʴ�.\n\n", 50);

    SetConsoleColor(12);
    TypeWriter("End.\n", 100);
    TypeWriter("- Too Late -\n\n", 100);
    SetConsoleColor(7);

    TypeWriter("������ ��ħ�� �巯������,\n", 50);
    TypeWriter("�� ����� �̹� ����� ���� �����̰� �־���.\n", 50);
    TypeWriter("�߹��յ�, ��ȸ��, ��ħ���� �ƹ��͵� ���� ���ߴ�.\n\n", 50);
    TypeWriter("����� �׳� ��, �׸��� ������ �������.\n", 50);
    TypeWriter("�׸��� ������, ��ġ �ƹ� �ϵ� ������ �� ��� �귯����.\n\n", 50);

    TypeWriter("--- [���� ����] ---\n", 40);
    std::cin.get();
    ClearScreen();
}
void TrueEnding()
{
    ClearScreen();

    SetConsoleColor(14); // ������ Ȳ�ݺ�
    TypeWriter("���۽��� ������ ��ġ�� ����� �����...\n", 60);
    TypeWriter("�ذ� �ִ� ������ ����� ����, �׸��� �ݱ�� �ּ��� ����.\n", 60);
    TypeWriter("�� ��� ���� �����ϰ� �ǻ�Ƴ���.\n\n", 60);

    TypeWriter("���� ���� ������ ��������� ������ �ڱ�ģ��.\n", 50);
    TypeWriter("�η���� ��ȸ�� ���� �������, ���� �ϼ��� ���� ���丸�� ���Ҵ�.\n\n", 60);

    TypeWriter("��� �ӿ��� õõ�� �Ͼ ����� �ٽ� �� �� �ǽ��� �����Ѵ�.\n", 50);
    TypeWriter("������ �����ߴ� ����, ������ ����� �տ��� �ϼ��ȴ�.\n", 50);
    TypeWriter("������ �ٶ��� �Ҿ����, �ź�ο� ����� ���� ���Ѵ�.\n\n", 60);

    SetConsoleColor(13); // �ź�ο� �����
    TypeWriter("�ּ��� �ϼ�����, ������ ��鸮�� �ð����� �����ϴ� ���ϴ�.\n", 50);
    TypeWriter("��� �ȿ��� ������ ���� �����ϸ�, ������ �ΰ��� ����� ����.\n\n", 60);

    TypeWriter("���� ����� �� �̻� ����� ���簡 �ƴϴ�.\n", 50);
    TypeWriter("������ �Ժη� �ǵ帱 �� ����, �� �ٸ� ������ ����� �ŵ쳵��.\n\n", 60);

    TypeWriter("������ ��Ұ� ������ ���� �����ϴ� ��迡��,\n", 50);
    TypeWriter("������ ������ ���� ����� ��ٸ���.\n\n", 70);

    SetConsoleColor(14);
    TypeWriter("���̰��� ������ ���ο� �����̴�.\n\n", 70);

    SetConsoleColor(14);
    TypeWriter("End.\n", 100);
    TypeWriter("- The Ritual Was Completed -\n\n", 100);
    SetConsoleColor(7);

    TypeWriter("����� ���� �ݱ⸦ �Ѿ��,\n", 50);
    TypeWriter("�� ���� ����� �ΰ� �ʸ��� ����� �̲�����.\n\n", 50);
    TypeWriter("�� �̻� �η���, ��ȸ�� ����.\n", 50);
    TypeWriter("������ ���� ����� �߽����� �ٽ� �¾��.\n\n", 50);

    TypeWriter("--- [���� ����] ---\n", 40);
    std::cin.get();
    ClearScreen();
}
