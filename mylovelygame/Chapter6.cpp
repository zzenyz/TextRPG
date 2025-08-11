#include "Chapter6.h"

void Chapter6Intro()
{
    ClearScreen();

    TypeWriter("�󰡸� �������� ��� �տ� ������ ����� �巯����.\n", 40);
    TypeWriter("�״� ���� � ��Ҹ��� ���Ѵ�.\n", 40);
    TypeWriter("\"���� ������ ���� ��� �ذ�� �� ����. �����־ ���� ����.\"\n", 50);
    
    TypeWriter("�׷��� ����� ��ȣ�ϰ� ���Ѵ�.\n", 40);
    TypeWriter("\"���� ������ �ʾҽ��ϴ�.\"\n", 50);

    TypeWriter("������ ���� �����̸� �Ǿ��� ǥ���� ��������\n", 40);
    TypeWriter("����� �ƹ����� ���� ���� ä ������ ����ģ��.\n", 40);
    TypeWriter("����� �Ƹ��� ���� �� ���� �������� ��� ���� ������ �̲��� ����.\n\n", 50);

    SetConsoleColor(12);
    TypeWriter("[��� �̵�: ������ ���� �Ա�]\n", 40);
    SetConsoleColor(7);

    TypeWriter("--- [����Ϸ��� Enter] ---\n", 30);
    std::cin.get();
    ClearScreen();
}

void Chapter6Explore()
{
    int choice = 0;
    bool fingerFound = false;
    bool ritualMarkFound = false;
    bool diaryFound = false;

    while (true)
    {
        ClearScreen();
        TypeWriter("���� �ȿ��� ���� �������� ���� �ִ�. ��� �����ұ�?\n\n", 40);
        TypeWriter(" 1. ���� ����\n", 30);
        TypeWriter(" 2. �ٴ�\n", 30);
        TypeWriter(" 3. �� ���� ����\n", 30);
        TypeWriter(" 4. Ž�� ����\n\n", 30);
        TypeWriter("����: ");

        std::cin >> choice;
        ClearScreen();

        switch (choice)
        {
        case 1:
            if (!fingerFound)
            {
                fingerFound = true;
                SetConsoleColor(12);
                TypeWriter("[����] ���� ���� �߰�\n\n", 40);
                SetConsoleColor(7);
                TypeWriter("���� �ȿ��� ������� �߸� �հ��� �� ���� �߰ߵǾ���.\n", 50);
                TypeWriter("������ �̰����� ������ ���� �������� �и��ϴ�.\n\n", 50);
            }
            else
            {
                TypeWriter("�̹� ������ ���Դϴ�.\n\n", 30);
            }
            break;

        case 2:
            if (!ritualMarkFound)
            {
                ritualMarkFound = true;
                SetConsoleColor(12);
                TypeWriter("[����] �ٴ�\n\n", 40);
                SetConsoleColor(7);
                TypeWriter("�ٴڿ� �������� �������� ���� ������ ������ ���� �ִ�.\n", 50);
                TypeWriter("������ �ݴ��� �ǽ��� �������� �Ͻ��ϴ� ���ϴ�.\n\n", 50);
            }
            else
            {
                TypeWriter("�̹� ������ ���Դϴ�.\n\n", 30);
            }
            break;

        case 3:
            if (!diaryFound)
            {
                diaryFound = true;
                SetConsoleColor(12);
                TypeWriter("[����] �� ���� ����\n\n", 40);
                SetConsoleColor(7);
                TypeWriter("�� �������� ������ �ϱ� ������ �߰��ߴ�.\n", 50);
                TypeWriter("�������� ��а� ���⿡ ���� �� �� ���� �����.\n", 50);
                TypeWriter("�� �ۿ��� �ڽ��� ��Ű�� ���� ����, ������ �ǵ帱 �� ���� ������ ���Ű� ���� �ִ�.\n\n", 60);
            }
            else
            {
                TypeWriter("�̹� ������ ���Դϴ�.\n\n", 30);
            }
            break;

        case 4:
            if (fingerFound && ritualMarkFound && diaryFound)
            {
                TypeWriter("���ڱ� �Ӹ��ӿ��� �������� ���� ������ �з��´�!\n", 70);
                TypeWriter("������ ����������, ������ ������ �Ѳ����� ����� ������.\n", 70);

                SetConsoleColor(12);
                TypeWriter("�� ��� �ӿ��� ���̴� ����... �ٸ� �ƴ� ��� �ڽ��� ��!\n", 70);
                TypeWriter("������ ��ǥ���� �� ���� ���� ���������...\n\n", 70);
                SetConsoleColor(7);

                TypeWriter("��� �ܼ��� ��������, ���ǲ�� ������ ������ �巯����.\n\n", 50);
                TypeWriter("���� �� ���� Ȯ���ϱ� ����, ������ ������ ������ ����.\n\n", 50);

                TypeWriter("--- [����Ϸ��� Enter] ---\n", 30);
                std::cin.ignore();
                std::cin.get();
                return;
            }
            else
            {
                TypeWriter("���� ��� �ܼ��� ã�� ���ߴ�. �� �����ؾ� �Ѵ�.\n\n", 50);
                Sleep(1000);
            }
            break;

        default:
            TypeWriter("�ùٸ� ��ȣ�� �Է��ϼ���.\n", 30);
            Sleep(1000);
            break;
        }

        TypeWriter("--- [����Ϸ��� Enter] ---\n", 30);
        std::cin.ignore();
        std::cin.get();
    }
}
