//#include "Chapter5.h"
//
//void Chapter5::ShowIntro() {
//    std::vector<std::string> lines = {
//        "[���� �� �Ա�]\n",
//        "\n������ ���� ������ ���� ���� �ܰ�, �������� ��� �ִ� �󰡿� �����ߴ�.\n",
//        "\n������ �� ���� ǥ�õǾ� �ְ�, ������ �ռ� ���� �޸� �������� �پ� �ִ�.\n",
//        "\n'���� ������ ������ �������� �𸥴ٴ� ������ �����.\n",
//        "\n������ ������� �������־�����, �� �ں��� ������ �����ϸ� �������� �Ѵٰ� �ߴ�.\n",
//        "\nȦ�� ���� ����� ��� ���� ���̽��� �� ������ �߰����� �ű��.\n",
//        "\n���� ������ �߰��̰�, �ٶ��� �����ϰ� �Ҿ�´�.\n",
//        "\n������ ���ǿ� ���ݾ� �ٰ����� ����� ���...\n"
//    };
//
//    for (const auto& line : lines) {
//        TypeWriter(line, 30);
//        std::this_thread::sleep_for(std::chrono::milliseconds(300));
//    }
//
//    TypeWriter("\n--- [����Ϸ��� Enter] ---\n", 30);
//    std::cin.get();
//    ClearScreen();
//}
//
//void Chapter5::ExploreMap() {
//    int choice;
//
//    while (true) {
//        ClearScreen();
//        TypeWriter("========================================\n", 20);
//        TypeWriter("[�� ���� ����]\n\n", 20);
//        TypeWriter("�� ���� �ձ۾��� �޸� �پ� �ִ�.\n", 20);
//        
//        TypeWriter("  1. �Ž�       - \"������ ������ ���� ���� ������ ���� �ּ�. ������ ���캸��.\"\n", 20);
//        TypeWriter("  2. ���Ͻ�     - \"������ ���� �ӿ� ���� ���� ���ڵ��� �׿� �ּ�. ���� ������ ������ ����.\"\n", 20);
//        TypeWriter("  3. �ȹ�       - \"������ ���������� �ӹ� ���� ���̿�. ���� �������ŵ� ������ �ൿ�ϰ�.\"\n", 20);
//        TypeWriter("  4. �ٶ���     - \"���� ���� �ʰ����� ���ǵ��� ���̿�. ���� ����� ���� �������� ����.\"\n\n", 20);
//
//        TypeWriter("0. �޴��� ���ư���\n", 20);
//        TypeWriter("������ ��Ҹ� �����ϼ���: \n> ", 20);
//
//        std::cin >> choice;
//        std::cin.ignore();
//
//        switch (choice) {
//        case 1:
//            ExploreLivingRoom();
//            break;
//        case 2:
//            ExploreBasement();
//            break;
//        case 3:
//            ExploreMasterRoom();
//            break;
//        case 4:
//            ExploreAttic();
//            break;
//        case 0:
//            return;
//        default:
//            TypeWriter("�߸��� �Է��Դϴ�.\n", 20);
//            system("pause");
//            break;
//        }
//    }
//}
//
//void Chapter5::ExploreLivingRoom() {
//    int choice;
//    bool clueFound = false;
//
//    while (true) {
//        ClearScreen();
//        TypeWriter("[�Ž�]\n\n", 20);
//        TypeWriter("���� ���Ŀ� ���� ���� Ź�ڰ� �������� ���� �ִ�.\n", 20);
//        TypeWriter("������ ���ٷ� ���� ���ڰ� �ɷ� �ִ�.\n\n", 20);
//        TypeWriter("���� ������ ��:\n", 20);
//        TypeWriter("  1. ���� ����\n", 20);
//        TypeWriter("  2. ���� ��\n", 20);
//        TypeWriter("  3. å��\n", 20);
//        TypeWriter("0. ���ư���\n> ", 20);
//
//        std::cin >> choice;
//        std::cin.ignore();
//        ClearScreen();
//
//        switch (choice) {
//        case 1:
//            if (!clueFound) {
//                TypeWriter("[���� ����]\n\n", 20);
//                TypeWriter("�ູ�� ���̴� ���� �����̴�.\n", 20);
//                TypeWriter("�����, �� ���̴¡�\n", 20);
//                TypeWriter("��? �� ���̡� �������ݾ�?\n", 20);
//                SetConsoleColor(12);
//                TypeWriter("(�ܼ� ȹ��: ���� ����)\n", 20);
//                SetConsoleColor(7);
//                clueFound = true;
//                SetClue1Found();
//            }
//            else {
//                TypeWriter("�̹� �� �����̴�. �� �̻� �ܼ��� ����.\n", 20);
//            }
//            break;
//        case 2:
//            TypeWriter("[���� ��]\n\n", 20);
//            TypeWriter("������ ������ �׿� �ְ� ������ �������� �����ٴѴ�.\n", 20);
//            break;
//        case 3:
//            TypeWriter("[å��]\n\n", 20);
//            TypeWriter("���� ������ ������ ��ȭå���� ���� �ִ�.\n", 20);
//            break;
//        case 0:
//            return;
//        default:
//            TypeWriter("�߸��� �Է��Դϴ�.\n", 20);
//            break;
//        }
//        system("pause");
//    }
//}
//
//void Chapter5::ExploreBasement() {
//    int choice;
//    bool clueFound = false;
//
//    while (true) {
//        ClearScreen();
//        TypeWriter("[���Ͻ�]\n\n", 20);
//        TypeWriter("������ ���� ��, ������ �ڽ��� �������� ��ҿ� ��� �ִ�.\n\n", 20);
//        TypeWriter("���� ������ ��:\n", 20);
//        TypeWriter("  1. ������ ����\n", 20);
//        TypeWriter("  2. ���� ��\n", 20);
//        TypeWriter("  3. �ܼ�Ʈ ��\n", 20);
//        TypeWriter("0. ���ư���\n> ", 20);
//
//        std::cin >> choice;
//        std::cin.ignore();
//        ClearScreen();
//
//        switch (choice) {
//        case 1:
//            if (!clueFound) {
//                TypeWriter("[������ ����]\n\n", 20);
//                TypeWriter("���� �ȿ��� ���ٷ� �Ź� ������ ���� �ִ�.\n", 20);
//                TypeWriter("�� ������ ��� ������ ���� ���´�:\n", 20);
//                TypeWriter("������ ã�ư��� ������ �湮���� �� �� ���Ҹ�\n", 20);
//                SetConsoleColor(12);
//                TypeWriter("(�ܼ� ȹ��: �Ź� ����)\n", 20);
//                SetConsoleColor(7);
//                clueFound = true;
//                SetClue2Found();
//            }
//            else {
//                TypeWriter("�̹� ������ ���ڴ�.\n", 20);
//            }
//            break;
//        case 2:
//            TypeWriter("[���� ��]\n\n", 20);
//            TypeWriter("������ ĵ��� ���� �������� ���� �ִ�.\n", 20);
//            break;
//        case 3:
//            TypeWriter("[�ܼ�Ʈ ��]\n\n", 20);
//            TypeWriter("�Ź����� ���� �ְ�, �̹����� ���� �ִ�.\n", 20);
//            break;
//        case 0:
//            return;
//        default:
//            TypeWriter("�߸��� �Է��Դϴ�.\n", 20);
//            break;
//        }
//        system("pause");
//    }
//}
//
//void Chapter5::ExploreMasterRoom() {
//    int choice;
//
//    while (true) {
//        ClearScreen();
//        TypeWriter("[�ȹ�]\n\n", 20);
//        TypeWriter("�̺��� ���� ������ ħ���, Ŀư�� ���� ���� â��.\n", 20);
//        TypeWriter("�� �ȿ��� ���� ���Ҹ��� �鸮�� ���� ������ ���.\n\n", 20);
//        TypeWriter("���� ������ ��:\n", 20);
//        TypeWriter("  1. ȭ���\n", 20);
//        TypeWriter("  2. Ŀư �� �׸���\n", 20);
//        TypeWriter("  3. ħ�� ��\n", 20);
//        TypeWriter("0. ���ư���\n> ", 20);
//
//        std::cin >> choice;
//        std::cin.ignore();
//        ClearScreen();
//
//        switch (choice) {
//        case 1:
//            TypeWriter("[ȭ���]\n\n", 20);
//            TypeWriter("��ƹ��� ���� ������ ����ƽ�� ���� �ִ�.\n", 20);
//            break;
//        case 2:
//            TypeWriter("[Ŀư �� �׸���]\n\n", 20);
//            TypeWriter("Ŀư ���̷� ���ǲ�� ��� ��ü ���� ���� ���δ�.\n", 20);
//            TypeWriter("������ �ٰ��� ���� �ƹ��͵� ����.\n", 20);
//            break;
//        case 3:
//            if (!bossAwakened) {
//                TypeWriter("[ħ�� ��]\n\n", 20);
//                TypeWriter("�������� ���ߴ� ����, �� �ȿ��� ���𰡰� �����δ�.\n", 30);
//                SetConsoleColor(12);
//                TypeWriter("�������� ���簡 ���۽��� ����� �巯����!\n", 30);
//                SetConsoleColor(7);
//                bossAwakened = true;
//                system("pause");
//                return;
//            }
//            else {
//                TypeWriter("�װ��� ���� �ƹ��͵� ����.\n", 20);
//            }
//            break;
//        case 0:
//            return;
//        default:
//            TypeWriter("�߸��� �Է��Դϴ�.\n", 20);
//            break;
//        }
//        system("pause");
//    }
//}
//
//void Chapter5::ExploreAttic() {
//    int choice;
//    bool keepsakeFound = false;
//
//    while (true) {
//        ClearScreen();
//        TypeWriter("[�ٶ���]\n\n", 20);
//        TypeWriter("���� ������ ���ڵ�� �ʰ����� ����� �ִ�.\n\n", 20);
//        TypeWriter("���� ������ ��:\n", 20);
//        TypeWriter("  1. �峭�� ����\n", 20);
//        TypeWriter("  2. õ���� ���� ����\n", 20);
//        TypeWriter("  3. ���� ����\n", 20);
//        TypeWriter("0. ���ư���\n> ", 20);
//
//        std::cin >> choice;
//        std::cin.ignore();
//        ClearScreen();
//
//        switch (choice) {
//        case 1:
//            if (!keepsakeFound) {
//                TypeWriter("[�峭�� ����]\n\n", 20);
//                TypeWriter("������ �ϳ��� ���� �ȿ� ���� �ִ�.\n", 20);
//                TypeWriter("� �޸� ������ ���� ���������, ��¾�� �Ʒ��� �����̴�.\n", 20);
//                SetConsoleColor(12);
//                TypeWriter("(��ǰ ȹ��: ������)\n", 20);
//                SetConsoleColor(7);
//                keepsakeFound = true;
//                SetKeepsake1Found();
//            }
//            else {
//                TypeWriter("������ �ܿ� Ư���� ���� ����.\n", 20);
//            }
//            break;
//        case 2:
//            TypeWriter("[õ���� ���� ����]\n\n", 20);
//            TypeWriter("������ �ٷ� õ�� �������� ������.\n", 20);
//            break;
//        case 3:
//            TypeWriter("[���� ����]\n\n", 20);
//            TypeWriter("�Ź��ٸ� �ܶ� ���� �ִ�.\n", 20);
//            break;
//        case 0:
//            return;
//        default:
//            TypeWriter("�߸��� �Է��Դϴ�.\n", 20);
//            break;
//        }
//        system("pause");
//    }
//}
