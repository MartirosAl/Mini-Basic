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
			file << "\t\t" << (char)((i % 26) + 'A' - 1) << (((i / 26) == 0) ? ' ' : (char)(i / 26 + '0' - 1)) << " dd ?" << endl;
	}

	for (int j = ptr_to_free; j < NTtemp; j++)
	{
		file << "\t\ttemp" << j << " dd ?" << endl;
	}

	for (int j = 700; j < NTX; j++)
	{
		file << "\t\ttemp" << j << " dd ?" << endl;
	}

	file << "\t\t" << "temp dd ?" << endl;

	file << "\t.code" << endl << "\tstart:" << endl;
	file << "\t call label_" << table_atoms[0].attribute1 << endl;
	file << "\t exit" << endl;

	int last_lable = -1;
	for (auto& i : table_atoms)
	{

		switch (i.type)
		{
		case 0:
			if (last_lable != -1)
			{
				file << "\tlabel_" << last_lable << " endp" << endl;
			}
			file << "end start" << endl;
			break;

		case 1:
			if (last_lable != -1)
			{
				file << "\t\t" << "call label_" << i.attribute1 << endl;
				file << "\tlabel_" << last_lable << " endp" << endl;
			}
			file << "\tlabel_" << i.attribute1 << " proc " << endl;
			last_lable = i.attribute1;
			break;

		case 2:
			file << "\t\tmov eax, " << N_to_S(i.attribute2) << endl;
			file << "\t\tmov " << N_to_S(i.attribute1) << ", eax" << endl;
			break;

		case 3:
			file << "\t\tcall label_" << i.attribute1 << endl;
			break;

		case 4:
			file << "\t\tcall label_" << i.attribute1 << endl;
			break;

		case 5:
			break;

		case 6:
			file << "\t\tmov eax, " << N_to_S(i.attribute1) << endl;
			file << "\t\tcmp eax, " << N_to_S(i.attribute2) << endl;
			switch (i.attribute3)
			{
			case 1:
				file << "\t\tJE label_" << i.attribute4 << endl;
				break;
			case 2:
				file << "\t\tJS label_" << i.attribute4 << endl;
				break;
			case 3:
				file << "\t\tJNS label_" << N_to_S(i.attribute4) << endl;
				break;
			case 4:
				file << "\t\tJE label_" << i.attribute4 << endl;
				file << "\t\tJS label_" << i.attribute4 << endl;
				break;
			case 5:
				file << "\t\tJE label_" << i.attribute4 << endl;
				file << "\t\tJNS label_" << i.attribute4 << endl;
				break;
			case 6:
				file << "\t\tJNE label_" << i.attribute4 << endl;
				break;
			}
			break;

		case 7:
			file << "\t\tmov eax, " << N_to_S(i.attribute1) << endl;
			file << "\t\tmov " << N_to_S(i.attribute2) << ", eax" << endl;
			break;

		case 8:
			//Как номстрок отличается от метки?

			break;

		case 9:
			file << "\t\tmov eax, " << N_to_S(i.attribute1) << endl;
			file << "\t\tcmp eax, " << N_to_S(i.attribute2) << endl;
			file << "\t\tJE label_" << i.attribute4 << endl;
			file << "\t\tJNS label_" << i.attribute4 << endl;
			// Что делать со step?
			break;

		case 10:
			file << "\t\tmov eax, " << N_to_S(i.attribute1) << endl;
			file << "\t\tadd eax, " << N_to_S(i.attribute2) << endl;
			file << "\t\tmov " << N_to_S(i.attribute1) << ", eax" << endl;
			break;

		case 11:
			file << "\t\tmov eax, " << N_to_S(i.attribute1) << endl;
			file << "\t\tadd eax, " << N_to_S(i.attribute2) << endl;
			file << "\t\tmov " << N_to_S(i.attribute3) << ", eax" << endl;
			break;

		case 12:
			file << "\t\tmov eax, " << N_to_S(i.attribute1) << endl;
			file << "\t\tsub eax, " << N_to_S(i.attribute2) << endl;
			file << "\t\tmov " << N_to_S(i.attribute3) << ", eax" << endl;
			break;

		case 13:
			file << "\t\tmov eax, " << N_to_S(i.attribute1) << endl;
			file << "\t\tmov ebx, " << N_to_S(i.attribute2) << endl;
			file << "\t\tmul ebx" << endl;
			file << "\t\tmov " << N_to_S(i.attribute3) << ", eax" << endl;
			break;

		case 14:
			file << "\t\tmov eax, " << N_to_S(i.attribute1) << endl;
			file << "\t\tmov ebx, " << N_to_S(i.attribute2) << endl;
			file << "\t\tdiv ebx" << endl;
			file << "\t\tmov " << N_to_S(i.attribute3) << ", eax" << endl;
			break;

		case 15:
			file << "\t\tmov eax, " << N_to_S(i.attribute1) << endl;
			for (int j = 1; j < i.attribute2; j++)
				file << "\t\tmul eax" << endl;
			file << "\t\tmov " << N_to_S(i.attribute3) << ", eax" << endl;
			break;

		case 16:
			file << "\t\tmov eax, " << N_to_S(i.attribute1) << endl;
			file << "\t\tinc eax" << endl;
			file << "\t\tmov " << N_to_S(i.attribute2) << ", eax" << endl;
			break;

		case 17:
			file << "\t\tmov eax, " << N_to_S(i.attribute1) << endl;
			file << "\t\tdec eax" << endl;
			file << "\t\tmov " << N_to_S(i.attribute2) << ", eax" << endl;
			break;
		}

		
	}

	file.close();
}

string Translator_to_assembler::N_to_S(int i) const
{
	string res;
	if (i <= 26)
	{
		res.push_back((char)(i + 'A' - 1));
	}
	else if (i <= 286)
	{
		res.push_back((char)(i % 26 + 'A' - 1));
		if ((i / 26) != 0)
			res.push_back((char)(i / 26 + '0' - 1));
	}
	else if (i >= ptr_to_free && i <= NTtemp)
	{
		res = "temp" + to_string((int)i);
	}
	else if (i >= 700 && i < NTX)
	{
		res = "temp" + to_string((int)i);
	}
	else
	{
		res = to_string((int)table_operands[i]);
	}

	return res;
}
