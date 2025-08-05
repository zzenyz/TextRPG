#include "Chapter2.h"

void Chapter2::ShowIntro()
{
	int introchoice;
	TypeWriter("��Ʈ�θ� ��ŵ�Ͻðڽ��ϱ�?\n", 40);
	TypeWriter("1. ��\n", 30);
	TypeWriter("2. �ƴϿ�\n", 30);
	TypeWriter("> ");
	std::cin >> introchoice;
	std::cin.ignore();

	if (introchoice == 1)
	{
		ClearScreen();
		return;
	}

	std::vector<std::string> lines = {
		"[�󱳵��� �Ա�]\n",
		"\n������ ǥ�ø� ���� ���㰡 �� ������ �տ� �����ߴ�.\n",
		"\nö���� �콽�� �־�����, ������ �ֱٿ� ������ �� ������ ���� �ִ�...\n",
		"\n����� ��ƴ ���̷� ���ɽ����� ������ ����.\n",
		"\n���� �����ߴ�. ����ġ��... �ұ��� ��ŭ.\n",
		"\n����� ���ǲ�� ��������.\n�Ǹ� ����� �������� ��â�� �ʸӷ� ���� ���� �־���.\n",
		"\n���츰�� �ƹ� �߸��� �������\n",
		"\n�� ��Ҹ��� ��ġ �ٷ� �翡�� �鸮�� �͸� ����.\n",
		"\n����� ������ ���� ������, ���� ��� ������ �߰����� �ű��.\n"
	};

	for (const auto& line : lines) {
		TypeWriter(line, 30);
		std::this_thread::sleep_for(std::chrono::milliseconds(300));
	}

	TypeWriter("\n--- [����Ϸ��� Enter] ---\n", 30);
	std::cin.get();
	ClearScreen();
}

void Chapter2::Warn()
{
	std::vector<std::string> lines = {
		"========================================\n",
		"[Chapter 2]\n\n",
		"�̰��� ���� ������ �˼����� ������ٴ� ������ �ִ� ����Դϴ�.\n\n",
		"�׷��� �ܼ��� ������ �ƴմϴ�. �Ϻδ� �����̾���, �Ϻδ� ����Ǿ����ϴ�.\n\n",
		"- ��Ҹ� �����ϸ� '�ܼ�'�� '��ǰ'�� ã������.\n",
		"- ������, �巯���⺸�� �������� ���� �����մϴ�.\n",
		"- ���𰡰��� ����� ���Ѻ��� �ֽ��ϴ�.\n\n",
		"�� ö���� �غ� ���� ���ƴٴ��� ������.\n",
		"========================================\n"
	};

	for (const auto& line : lines)
	{
		TypeWriter(line, 10);
		std::this_thread::sleep_for(std::chrono::milliseconds(300));
	}
}

void Chapter2::ExploreMap()
{
	std::vector<std::string> lines = {
		"========================================\n",
		"[���� ���� ����]\n\n",
		"������ ���� �𼭸��� �� ���� ǥ�õǾ� �ִ�.\n\n",
		"  1. ����            - \"�� �濡 �ִ� �˼��� ���� �Ȱ��� �Ǹ��� ���.\"\n",
		"  2. ���� ����      - \"������ ���� ���ƿ��� ���߾�.\"\n",
		"  3. ���������        - \"�״� ���� ����� ȥ�ڸ� �ôٰ� ����.\"\n",
		"  4. ����ž           - \"�� ������ ������ ��� ������ ���� �־���.\"\n\n",
		"�޴��� ���ư��÷��� 0\n",
		"������ ��Ҹ� �����ϼ���: \n",
		"> "
	};

	for (const auto& line : lines)
	{
		TypeWriter(line, 5);
		std::this_thread::sleep_for(std::chrono::milliseconds(300));
	}
}

void Chapter2::ExploreCell()
{
	bool hasKeepsake = false;
	int choice;
	ClearScreen();
	while (true) {
		std::vector<std::string> intro = {
			"[����]\n\n",
			"öâ ���� �����ϰ� ��ο���.\n",
			"���� ������ ��:\n",
			"  1. öâ\n",
			"  2. �ٴ� ƴ\n",
			"  3. �� ����\n",
			"\n�޴��� ���ư��÷��� 0\n",
			"> "
		};

		for (const auto& line : intro)
			TypeWriter(line, 10);

		std::cin >> choice;
		system("cls");

		switch (choice) {
		case 1:
			TypeWriter("[öâ]\n\n", 10);
			TypeWriter("���ڱ��� �콼 ���ڱ��� ����� ���� �ִ�.\n", 10);
			TypeWriter("���� ���� ���� �߹����ƴ� �����ϱ\n", 10);
			break;

		case 2:
			if (!hasKeepsake) {
				TypeWriter("[�ٴ� ƴ]\n\n", 10);
				TypeWriter("�ٴ� ƴ���� ���� �콼 ������ �߰ߵȴ�.\n", 10);
				TypeWriter("ǥ�鿣 ������� ���ڱ��� �����ϴ�.\n", 10);
				TypeWriter("(��ǰ ȹ��: �콼 ����)\n", 10);
				hasKeepsake = true;
				SetKeepsakeFound();
			}
			else {
				TypeWriter("[�ٴ� ƴ]\n\n", 10);
				TypeWriter("�� �̻� ���� ��� ���� ����.\n", 10);
			}
			break;

		case 3:
			TypeWriter("[�� ����]\n\n", 10);
			TypeWriter("���� ����ϰ� ���� ���ڰ� ���δ�.\n", 10);

			SetConsoleColor(12);
			TypeWriter("\"����... ������ ��...\"\n", 10);
			SetConsoleColor(7);

			TypeWriter("����� ����������.\n", 10);
			break;

		case 0:
			return;

		default:
			TypeWriter("�߸��� �Է��Դϴ�.\n", 10);
			break;
		}

		TypeWriter("\n", 5);
		system("pause");
		ClearScreen();
	}
}


void Chapter2::ExploreTortureRoom()
{
	int choice;
	
	ClearScreen();
	while (true) {
		std::vector<std::string> intro = {
			"[���� ����]\n\n",
			"����� ������ ������ �����Ѵ�.\n",
			"���� ������ ��:\n",
			"  1. �� ����\n",
			"  2. �ٴ�\n",
			"  3. �� ƴ\n",
			"\n�޴��� ���ư��÷��� 0\n",
			"> "
		};

		for (const auto& line : intro)
			TypeWriter(line, 10);

		std::cin >> choice;
		system("cls");

		std::vector<std::string> lines;

		switch (choice) {
		case 1:
			lines = {
				"[�� ����]\n\n",
				"�콽�� ������ �������� �κ귯�� �ִ�.\n",
				"�������� �̰ɷ� ���� ���� �¾������� �𸥴�.\n"
			};
			break;
		case 2:
			lines = {
				"[�ٴ�]\n\n",
				"�ǰ� ����پ� ���� �ִ�.\n",
				"�󸶳� ���� �̰� �̰��� ���� �����\n"
			};
			break;
		case 3:
			TypeWriter("[��]\n\n", 10);
			TypeWriter("���� ���� ���� ������ ������ ��������.\n", 10);

			if (bossAwakened) 
			{
				TypeWriter("��� �������� ���ϴ� ���� �̹� ���� �ִ�.\n", 10);
				TypeWriter("������ �� ���� �� ��� �ְ�, �δ��� �� ���� �ִ�.\n", 10);
			}
			else
			{
				TypeWriter("��򰡿��� �ٶ��� ������� �Ҹ��� �鸰��...\n", 10);
				TypeWriter("���� õõ�� �����̸� ��� �������� �̾����� ��ΰ� ������!\n", 10);

				SetConsoleColor(12); // ������ ����
				TypeWriter("�� ����, ���𰡰� ����� �븰��!\n", 10);
				SetConsoleColor(7); // �� ���󺹱�

				bossAwakened = true;
				system("pause");
				return;
			}
			break;
		case 0:
			return;
		default:
			lines = { "�߸��� �Է��Դϴ�.\n" };
			break;
		}

		for (const auto& line : lines) {
			TypeWriter(line, 10);
			std::this_thread::sleep_for(std::chrono::milliseconds(200));
		}
		TypeWriter("\n", 5);
		system("pause");
		ClearScreen();
	}
}

void Chapter2::ExploreWardenOffice()
{
	int choice;
	ClearScreen();
	while (true) {
		std::vector<std::string> intro = {
			"[���������]\n\n",
			"������ ������� ������ ��. ������ ������ �����ɾ� �ִ�.\n",
			"���� ������ ��:\n",
			"  1. ����\n",
			"  2. å�� �� ����\n",
			"  3. ������ ĳ���\n",
			"\n�޴��� ���ư��÷��� 0\n",
			"> "
		};

		for (const auto& line : intro)
			TypeWriter(line, 10);

		std::cin >> choice;
		system("cls");

		std::vector<std::string> lines;

		switch (choice) {
		case 1:
			lines = {
				"[����]\n\n",
				"����ִ�. ������ �̹� ����� �� ������.\n"
			};
			break;
		case 2:
			lines = {
				"[å�� �� ����]\n\n",
				"������ ���̰� �������� ����� �ִ�.\n",
				"��� ���������� ����ϰ� ���ڰ� ���δ�.\n",
				"\"...�˼���ȣ 2719... ����... ����\"\n",
				"������ ��κ��� �˾ƺ� �� ����.\n",
				"(�б� ����� ���� ����)\n"
			};
			SetClue1Found();
			break;
		case 3:
			lines = {
				"[������ ĳ���]\n\n",
				"���谡 �ʿ��� ���δ�. �� �� ����.\n"
			};
			break;
		case 0:
			return;
		default:
			lines = { "�߸��� �Է��Դϴ�.\n" };
			break;
		}

		for (const auto& line : lines) {
			TypeWriter(line, 10);
			std::this_thread::sleep_for(std::chrono::milliseconds(200));
		}
		TypeWriter("\n", 5);
		system("pause");
		ClearScreen();
	}
}

void Chapter2::ExploreWatchtower()
{
	int choice;
	ClearScreen();
	while (true) {
		std::vector<std::string> intro = {
			"[����ž]\n\n",
			"���� ����� ������, ������ ���� ���� ������ ���´�.\n",
			"���� ������ ��:\n",
			"  1. ħ�� �Ʒ�\n",
			"  2. â��\n",
			"  3. Ź�� �� ��������\n",
			"\n�޴��� ���ư��÷��� 0\n",
			"> "
		};

		for (const auto& line : intro)
			TypeWriter(line, 10);

		std::cin >> choice;
		system("cls");

		std::vector<std::string> lines;

		switch (choice) {
		case 1:
			lines = {
				"[ħ�� �Ʒ�]\n\n",
				"�Ź��ٰ� ������ �����ϴ�.\n"
			};
			break;
		case 2:
			lines = {
				"[â��]\n\n",
				"£�� �Ȱ��� ���� �ٱ� ǳ���� ������ �ʴ´�.\n"
			};
			break;
		case 3:
			lines = {
				"[Ź�� �� ��������]\n\n",
				"\"2179�� ���� �Ȱ��� ���� �۴ٰ� �ߴ�.\n ���� �˼��� �׳� �� �������,\n �������� ����ħ����� ���� ��, \n �ڼ��� ������ �� �� ������...\"\n",
				"����� �ű⼭ ���� �ִ�.\n",
				"(�ܼ� ȹ��: ��������)\n"
			};
			SetClue2Found();
			break;
		case 0:
			return;
		default:
			lines = { "�߸��� �Է��Դϴ�.\n" };
			break;
		}

		for (const auto& line : lines)
		{
			TypeWriter(line, 10);
			std::this_thread::sleep_for(std::chrono::milliseconds(200));
		}
		TypeWriter("\n", 5);
		system("pause");
		ClearScreen();
	}
}