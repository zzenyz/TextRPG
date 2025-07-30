#include "Player.h"


bool Player::Save(std::ofstream& ofs) const {
    if (!ofs) return false;

    // ���ڿ� ����: null ����('\0') �����ؼ� ����
    ofs.write(name.c_str(), name.size() + 1);
    ofs.write(jobName.c_str(), jobName.size() + 1);

    // ������ ��� ����
    ofs.write(reinterpret_cast<const char*>(&hp), sizeof(hp));
    ofs.write(reinterpret_cast<const char*>(&maxHp), sizeof(maxHp));
    ofs.write(reinterpret_cast<const char*>(&atk), sizeof(atk));
    ofs.write(reinterpret_cast<const char*>(&def), sizeof(def));
    ofs.write(reinterpret_cast<const char*>(&level), sizeof(level));
    ofs.write(reinterpret_cast<const char*>(&karma), sizeof(karma));

    return !ofs.fail();
}

bool Player::Load(std::ifstream& ifs) {
    if (!ifs) return false;

    // null ����('\0')���� ������ ���ڿ� ����
    std::getline(ifs, name, '\0');
    std::getline(ifs, jobName, '\0');

    // ������ ��� ����
    ifs.read(reinterpret_cast<char*>(&hp), sizeof(hp));
    ifs.read(reinterpret_cast<char*>(&maxHp), sizeof(maxHp));
    ifs.read(reinterpret_cast<char*>(&atk), sizeof(atk));
    ifs.read(reinterpret_cast<char*>(&def), sizeof(def));
    ifs.read(reinterpret_cast<char*>(&level), sizeof(level));
    ifs.read(reinterpret_cast<char*>(&karma), sizeof(karma));

    return !ifs.fail();
}

