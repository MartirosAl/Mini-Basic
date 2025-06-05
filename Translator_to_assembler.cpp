#include "Translator_to_assembler.h"

Translator_to_assembler::Translator_to_assembler(string file_name)
{
	start_SA(file_name);
}

void Translator_to_assembler::Generate_assembler_code(string file_name)
{
	ofstream file;
	file.open(file_name);
	if (!file.is_open())
	{
		cerr << "Error opening file: " << file_name << endl;
		return;
	}
	file.clear();
	

	file << "include \\masm32\\include\\masm32rt.inc\n\n.386" << endl;

	file << "\t.data?" << endl << endl;
	for (int i = 0; i <= 286; i++)
	{
		if (table_operands[i] == 1)
			file << "\t\t" << (char)((i % 26) + 'A' - 1) << (((i / 26) == 0) ? ' ' : (char)(i / 26 + '0' - 1)) << " dd ?"<< endl;
	}
	for ()
	file << "\t\t" << "temp dd ?" << endl;

	file << "\t.code" << endl << "start:" << endl << endl;

	int last_lable = -1;
	for (auto& i : table_atoms)
	{
		switch (i.type)
		{
		case 1:
			file << "end start";
			break;

		case 2:
			if (last_lable != -1)
			{
				file << "\t\t" << "call label_" << i.attribute1 << endl;
				file << "\t" << last_lable << "endp" << endl;
			}
			file << "\tlabel_" << i.attribute1 << ": ";
			last_lable = i.attribute1;
			break;

		case 3:
			file << "\t\tmove " << N_to_S(i.attribute1) << ", " << N_to_S(i.attribute2) << endl;
			break;

		case 4:
			file << "\t\tcall label_" << N_to_S(i.attribute1 << endl;
			break;

		case 5:
			file << "\t\tcall label_" << N_to_S(i.attribute1 << endl;
			break;

		case 6:
			break;

		case 7:
			file << "\t\tmove eax, " << N_to_S(i.attribute1) << endl;
			file << "\t\tcmp eax," << N_to_S(i.attribute2) << endl;
			switch (i.attribute3)
			{
			case 1:
				file << "JE label_" << N_to_S(i.attribute4) << endl;
				break;
			case 2:
				file << "JS label_" << N_to_S(i.attribute4) << endl;
				break;
			case 3:
				file << "JNS label_" << N_to_S(i.attribute4) << endl;
				break;
			case 4:
				file << "JE label_" << N_to_S(i.attribute4) << endl;
				file << "JS label_" << N_to_S(i.attribute4) << endl;
				break;
			case 5:
				file << "JE label_" << N_to_S(i.attribute4) << endl;
				file << "JNS label_" << N_to_S(i.attribute4) << endl;
				break;
			case 6:
				file << "JNE label_" << N_to_S(i.attribute4) << endl;
				break;
			}
			break;

		case 8:
			file << "\t\tmove" << N_to_S(i.attribute1) << ", " << N_to_S(i.attribute2) << endl;
			break;

		case 9:
			break;

		case 10:
			break;

		case 11:
			break;

		case 12:
			break;

		case 13:
			break;

		case 14:
			break;

		case 15:
			break;

		case 16:
			break;

		case 17:
			break;

		case 18:
			break;
		}

		
	}
	file.close();
}

string Translator_to_assembler::N_to_S(int i) const
{
	if ((i / 26) != 0)
		return to_string((i % 26) + 'A' - 1) + to_string(i / 26 + '0' - 1);
	else
		return to_string((i % 26) + 'A' - 1);
}
