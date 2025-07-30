#include "Game.h"

void Game::Start() {
	/*Inventory& inv = player.GetInventory();

	std::cout << "[DEBUG] ��� �߰� �õ� 1\n";
	SleepMs(1000);
	inv.AddItem(EquipmentItem(10, "�Ź��", ItemType::Weapon, 1, 100,"??", 5, 0, 0));
	std::cout << "[DEBUG] ��� �߰� �Ϸ� 1\n";
	SleepMs(1000);
	inv.AddItem(EquipmentItem(13, "���� �����", ItemType::Armor, 1, 120,"??", 0, 3, 20));
	inv.AddItem(EquipmentItem(16, "���� ���", ItemType::Accessory, 1, 150,"??", 0, 5, 30));*/

	if (SaveManager::HasSavedGame()) {
		ClearScreen();
		TypeWriter("����� ������ �ֽ��ϴ�.\n", 40);
		TypeWriter("1. �� ����\n", 30);
		TypeWriter("2. �ҷ�����\n", 30);
		TypeWriter("> ");

		int choice;
		std::cin >> choice;
		std::cin.ignore();

		if (choice == 2) {
			if (SaveManager::LoadGame(player)) {    // LoadGame�� ����� ������ �ҷ����� �Լ�, ������ true ��ȯ
				SetConsoleColor(12); // ������
				TypeWriter("\n������ �ҷ��ɴϴ�...\n", 30);
				SetConsoleColor(7);
			}
			else {
				SetConsoleColor(12); // ������
				TypeWriter("�ҷ����⿡ �����߽��ϴ�... �� ������ �����մϴ�.\n", 30);
				SetConsoleColor(7);
				ShowIntro();
			}
		}
		else {
			ShowIntro();
		}
	}
	else {
		ShowIntro();
	}

	GameLoop();
}

void Game::ShowIntro() {
	std::vector<std::string> lines;
	std::string name;
	int jobChoice;

	ClearScreen();
	TypeWriter("����� �̸���? ");
	std::getline(std::cin, name);
	player.SetName(name);

	//ClearScreen();
	TypeWriter("������ �����ϼ���\n", 40);
	TypeWriter("1. ����\n", 30);
	TypeWriter("2. ǳ��������\n", 30);
	TypeWriter("3. ���л�\n", 30);
	TypeWriter("> ");
	std::cin >> jobChoice;
	std::cin.ignore(); // �ٹٲ� ����

	// ��ȿ�� �˻�
	if (jobChoice < 1 || jobChoice > 3) {
		TypeWriter("\n�߸��� �����Դϴ�. �⺻������ ������ �����˴ϴ�.\n\n");
		jobChoice = 1;
	}

	player.reSetJob(jobChoice);

	ClearScreen();
	SetConsoleColor(12); // ������
	TypeWriter(name + "��, �ݰ����ϴ�.\n", 40);
	SetConsoleColor(7);

	TypeWriter("����� " + player.GetJobName() + "�Դϴ�.\n\n", 35);
	SleepMs(1500);
	ClearScreen();

	int introchoice;
	TypeWriter("��Ʈ�θ� ��ŵ�Ͻðڽ��ϱ�?\n", 40);
	TypeWriter("1. ��\n", 30);
	TypeWriter("2. �ƴϿ�\n", 30);
	TypeWriter("> ");
	std::cin >> introchoice;
	std::cin.ignore(); // �ٹٲ� ����

	if (introchoice == 1)
	{
		ClearScreen();
		return;
	}

	// ������ ��Ʈ ����
	switch (jobChoice) {
	case 1:
		lines = {
			"[��� �Ҹ��� �鸰��.]\n",
			"�װ� � ��, ó�� �ͽ��� �� ������ �� ����ٴϴ� �Ҹ�����.\n",
			"����� ������ �ʾƵ� ���߸� �߰�, �鸮�� �ʾƵ� ����Դ�.\n",
			"������ ȥ�� ����� ����������, �̹� �ǡ� �ٸ���.\n",
			"�̰� �׳� ������ ��ȥ�� �ƴϴ�.\n",
			"���� �ְ�, ��Ʋ�Ȱ�, Ǯ��߸� �ϴ� �翬�̴�.\n",
			"�ҸӴϲ��� ������ ���� �ϸ� ���߾���.\n",
			"���̰� �� ���ڴ١� �̰� ���ϸ�, ������ �ϰ� �ǰξ�.��\n",
			"�� ����, ����� �ճ����� ����� ��ȴ�.\n",
			"������ �� ȥ�� Ǯ�� �Ͷ�.��\n",
			"�׸��� ����, ����� �߹ؿ� �� ��Ұ� �ִ�.\n"
		};
		break;
	case 2:
		lines = {
			"[�볿���� ���ϰ� �� ���� �پ���.]\n",
			"�� �ҳడ ������ �� �տ� �� �־���.\n",
			"�׳�� ���� �İ� �־���, ���𰡸� ������.\n",
			"�� ���� �ǰ� �귶��.\n",
			"����� �ڸ����� �Ͼ ������ ���.\n",
			"���� ���� �� ���� ����Ű�� �־���.\n",
			"�װ� �̻��ߴ�.\n",
			"�� ��Ҵ� ����� �ƹ��� ������ �ʾҴ� ���ݱ��� �������̾���.\n",
			"ǳ������ ���Ѵ�.\n",
			"**����� ��ȯ�Ǿ�� �Ѵ�.**\n",
			"���� ���� ȥ�� ������,\n",
			"���� ���� ���ְ� ���´�.\n",
			"����� ���帧���� ���� ����.\n",
			"�׷��� �� �帧�� ����, ������ ��ٸ����� �ƹ��� �𸥴�.\n"
		};
		break;
	case 3:
		lines = {
			"[����� ���� ��, �⵵�ϰ� �־���.]\n",
			"������ ������ �̻��ϰ�, �⵵ ���� ����� ���� �ʾҴ�.\n",
			"â�ۿ���, ������ ����� �̸��� �ӻ迴��.\n",
			"����å�� ������ ��������.\n",
			"��ġ, ���� �������� ������ ��������.\n",
			"����� �ϴ´�. ���� ���� �ֱ⿡.\n",
			"�׷��� ���� ��ſ��� ���� **���� ���� �ʾҴ�.**\n",
			"���� ����� ���� ����, ������ ħ���� ���.\n",
			"�װ��� ������ ����� ���� �̵��� �⵵��\n",
			"������� ���� ä �׿� �ִ�.\n",
			"�׸��� ����� �� �⵵�� ���� �� ���� �Դ�.\n"
		};
		break;
	}

	// ���
	for (const auto& line : lines) {
		TypeWriter(line, 35);
		std::this_thread::sleep_for(std::chrono::milliseconds(300));
	}

	TypeWriter("\n--- [����Ϸ��� Enter] ---\n", 30);
	std::cin.get();
	ClearScreen();

	lines = {
		"[���� ���� �Ա� ��]\n",
		"����� ��������, ���� ������ ��ģ �󱼷� ����� �����Ѵ�.\"\n",
		"\"���� ���̱�.\"\n",
		"\"�� �������� 30�� ������ ������ �� ���� ���� ��ӵǰ� �ּ�\"\n",
		"\"�󰡿��� �����Ҹ��� ������ �ʰ�,  �칰���� �㸶�� ���� ���� ���´ٴ� ���� ������ �Լ�\"\n",
		"\"���̵��� �Ǹ��� �ô޸���,  ����� ���� ���� ����ų�, ������⵵ �߼ҡ�\"\n",
		"\n��... ��... ����...\n",
		"\n������ �߾�ŷȴ�.\n",
		"\n\"ó���� �ٵ� �쿬�̶� ���������� ���� ������ �׷��� ���� ������.\"\n"
		"\"�� ſ����, �����̵��� �ϳ��Ѿ� ������ ������ �ּ�.\n"
		"\"�̴�ζ�顦 �� ������ ���� ���������� �𸣿�.\"\n"
		"\"�ε� �� ��� �߾��� ������ ������ ������ �����ֽÿ�.\"\n"

		"\n������ ��� �����鼭�� �ͼ��� ����� ���...\n"
		"���� ������� �η����� �� ���� ����� ������ �͸� ����.\n"
		"�̰��� ������ ������ �� ã�ƾ߸� ��.\n"
	};

	for (const auto& line : lines) {
		TypeWriter(line, 35);
		std::this_thread::sleep_for(std::chrono::milliseconds(300));  // ��� ���鼭 Ÿ�ڱ� ȿ�� ��
	}

	TypeWriter("\n--- [����Ϸ��� Enter] ---\n", 30);
	std::cin.get();
	ClearScreen();
}


void Game::GameLoop() {
	ShowMainMenu();
}

void Game::ShowMainMenu() {
	while (true)
	{
		ClearScreen();
		TypeWriter("���� �޴�\n", 40);
		TypeWriter("1. ���丮 ����\n", 30);
		TypeWriter("2. �κ��丮\n", 30);
		TypeWriter("3. ����\n", 30);
		TypeWriter("4. ����\n", 30);
		TypeWriter("5. ����\n", 30);
		TypeWriter("> ");

		int choice = 0;
		std::cin >> choice;
		std::cin.ignore();

		ClearScreen();

		switch (choice) {
		case 1:
			ShowStoryMenu();
			break;
		case 2:
		{
			Inventory& inv = player.GetInventory();


			ClearScreen();
			inv.ShowInventory();         // ��ȣ �����ؼ� ���
			inv.ShowEquippedItems();

			while (true) {
				int inputNum = 0;
				TypeWriter("\n������ ������ ��ȣ�� �Է��ϼ��� (0: ���ư���)", 30);
				TypeWriter("> ");

				std::cin >> inputNum;
				std::cin.ignore();

				if (inputNum == 0) break;  // 0 �Է� �� �޴��� ���ư�

				if (inputNum < 1 || inputNum >(int)inv.items.size()) {
					TypeWriter("�߸��� ��ȣ�Դϴ�. �ٽ� �õ��ϼ���.\n", 30);
					continue;
				}

				ItemType selectedType = inv.items[inputNum - 1].type;
				if (selectedType == ItemType::Consumable) {
					TypeWriter("�Һ� �������� ������ �� �����ϴ�.\n", 30);
					continue;
				}

				// ��ȣ�� ������ ã�Ƽ� ����
				int itemId = inv.items[inputNum - 1].id;
				inv.EquipItem(itemId);

				TypeWriter("�������� �����Ǿ����ϴ�.\n", 30);
			}
			break;
		}
		case 3:
			ShowShopItems(player);
			break;
		case 4:
			SaveManager::SaveGame(player);
			break;
		case 5:
			TypeWriter("������ �����մϴ�.\n");
			return;
		default:
			TypeWriter("�߸��� �����Դϴ�. �ٽ� �õ��ϼ���.\n");
			std::this_thread::sleep_for(std::chrono::seconds(1));
			break;
		}
	}
}

void Game::ShowStoryMenu() {
	std::vector<std::string> chapterTitles =
	{
		"�μ��� ���� ����\n",
		"�콼 ����\n",
		"���� �ո�ð�\n",
		"��ȫ�� �Ӹ���\n",
		"��Ӵ��� �ϱ���\n",
		"���� ī��Ʈ ������\n"
	};

	TypeWriter("== ����� ���� ==\n", 40);

	int unlocked = player.GetUnlockedChapter();
	int i = 0;
	while (true)
	{
		for (i = 0; i < chapterTitles.size(); ++i)
		{
			std::string line = "<chapter " + std::to_string(i + 1) + "> ";
			if (i < unlocked)
			{
				line += chapterTitles[i] + "\n";
			}
			else
			{
				line += "??? (���)\n";
			}
			TypeWriter(line, 30);  // �� ���� ���
		}

		TypeWriter("\n�޴��� ���ư��÷��� 0\n", 30);
		TypeWriter("\n������ é�� ��ȣ�� �Է��ϼ���: \n", 30);
		TypeWriter("> ");
		int choice;
		std::cin >> choice;
		std::cin.ignore();

		if (choice == 0)
		{
			break;
		}

		if (choice < 1 || choice > 6) {
			TypeWriter("�߸��� ��ȣ�Դϴ�.\n", 40);
			ClearScreen();
			continue;
		}

		if (player.GetUnlockedChapter() < choice) {
			TypeWriter("���� ��� é���Դϴ�.\n", 40);
			ClearScreen();
			continue;
		}

		//StartChapter(choice);
		break;
	}

}




