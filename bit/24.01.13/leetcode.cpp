#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* repeatLimitedString(char* s, int repeatLimit)
{
	char* ans = (char*)malloc(sizeof(char) * (strlen(s) + 1));
	int arr[26] = { 0 };

	char* cur = s;

	while (*cur != '\0')
	{
		arr[*cur - 97]++;
		cur++;
	}

	int max1 = 25;
	int max2 = 24;
	int repeat = 0;
	int i = 0;

	if (arr[max2] == 0)
	{
		for (int j = max2 - 1; j >= 0; j--)
		{
			max2 = j;
			if (arr[j] != 0)
			{
				break;
			}
		}
	}


	while (max2 >= 0)
	{
		if (arr[max1] == 0 || arr[max2] == 0)
		{
			if (arr[max1] == 0)
			{
				max1 = max2;
				repeat = 0;
			}

			for (int j = max2 - 1; j >= 0; j--)
			{
				max2 = j;
				if (arr[j] != 0)
				{
					break;
				}
			}
		}

		if (max1 == 1)
		{
			int m = 0;
		}

		if (arr[max2] == 0 || (max1 == 0 && max2 == 0))
			break;

		if (repeat < repeatLimit)
		{
			ans[i++] = max1 + 97;
			arr[max1]--;
			repeat++;
		}
		else
		{
			ans[i++] = max2 + 97;
			arr[max2]--;
			if (arr[max1])
			{
				repeat = 0;
			}
			else
			{
				if (arr[max2] == 0)
					repeat = 0;
				else
					repeat = 1;
			}
		}
	}

	while (repeat < repeatLimit && arr[max1] > 0)
	{
		ans[i++] = max1 + 97;
		arr[max1]--;
		repeat++;
	}

	ans[i++] = '\0';
	return ans;
}

int main()
{
	char arr[] = "ohiyrcdycufcgayvxpgqgwnpvabvtwouwcfmouywnualudijknjsypvxsanfahrcnxquasiekekyurlxqthmblcufnrkgwzqrxdcaykearbomfkdhoitgwymnmnftijhvcqcjfilkfsynridkwfyzbveeqmhoecjjissehvfmsfadzdzsedmxpndasyfaqwztgyglpqwcemyscvxcqdxpvytmiieadaltfrccjjdvjjqwkjeefezmhofaaeuwiowkyindhknsykdkgwcmxuqpoopkfqxzllfjuqxobhmnjxhcuvezvqpxicpryugkqpanzpuqpxgbdxxbtglkpllonxspjrtiniiitmuqeojrrbheppqgmhtaqkqpgrktzbvmcdajdygxegippxavdujujnrnphlqmsvygwicgmjkcasmafmdezulgdhwvlejexhibqxhvvdvwbjxufooyryezgvtztflxnmlpfpllrychnzwqhgdglavlgakffunrccvxhuqwumhsfbaovbsvtumakchdfaztrmibyrjrzoejxqsfajyukmekikcwklbbuczggjhjbjqmcspzwuvxywnztyfxuxlffxcigzvebeaisjgmgxerihgsueazbhqshvjhdtbjmrwkturntrexuyrtlbpnmqgmhzrpjcnhtldzxnottadawfdabzexkvslubojfyolksollifqsisiqjybizvkbjdbdelsvglvwxmkdsmufwaolthbitxzdnriedylmywbyblmtzrdwsvqtmvsejtpdfllijveaficnkgzdeugwekmiigbdonioahqxmwiwojdzjqdrzcogdiwspbwhvkeagwqvhwrajyiubuzysqxoajduzetyyapnroecpqzgsmerfqgoqrzckqkhheawgexnlrcpkoreuovrihgrwkzvdfpzszbfairqvrhldcmptssrojtojuiqwlqqvhdwnzoiyfijophfslghhgnklecfcpdrhvxavpywyfhzzbgczmcszhdpueljakkoiuaunigmtfxxhsibkbnqucqakcoqmanhggmeiupvbnxdqrravbeuhoaywujzrwgsywizmoyngxhfzswtotwflghywmgatzoperkxxufvrlbxfxlogmambpbclksvslogqdiyckuelbzlzaaymrfaasgbefrbdzlaxzhuincymxjhkyhgdfopyuhsiovftobnsdwsujowlqihdoiarwtglkoukuyjakbbtajfnljmxzjzyslefeqyoautandmekhchzqkncfpnqkunlzmzrukocarnkpphycgwfwqcxkkkhyevajwoiibbcfnqmmvozsootbqrsfqxgjzilczydnzsdhkgxnipvuyebtxnqjdtnrnlkmdhextuxvammyhimjxfgqizxgzekvfoanwmbgaxolobfrlzqkpdexauyiilcpepkqfezxebmnddknkbnhludlooihhsxuaawbnailffvvaqxnnrojyspwgdnustsbiurnbvbyxowctpxvdluxgfugozesufgyixdcgiqpedpgfieydejlyudxkhnwdudswzlzhvsbuwhcllvveiexkpjajclaypnlvjlbwzhzdjhmppgygtucxxjuxdbmeyoimacrpiyddjmhldsykvpmghtdoycpjgldrmwnmhoooikdfahiygisctbuyqfihayuyugpmrfvtchejkcilccdmxxhbdjdvbfypjjucwtbhepvivvmouhehtjrhseiwtlzrkdhbnrnaogcoqgtthpnstzguopuyzwxmpfxebgtuoavfzhzkcivjpcjjwfpoytofhsdiitjywqjoldpjsygppadwjvqvmmlddjrwnhrylxuumavxzncxeoominkhysnaoffygulmqikbjasqcinsyegvolppiwjouozxaxbcmqloacnjfuriakrcqxtrcnsrtuexrwyiiyobkptmukikmgvvegogavqycvwgllmgezdbefacmefckdfhhnfnhebtedccvmedtytzvbrskryquhvddjxvhmwwawxbcaqloomaqpjajfhqcqzuqhnnlzjoinrvyqiqualrymjfenmqkeoqpremqarshibctvkoutcebgnvbddtjfhqeqpbqwauzjmoocriwhmpdobycgfubnylptjsuboivfcjgjasuededqoofkavuzqgmzhceiboirezszxzibrajnrarjthddwrjoerpfthodcdlycjusnnvhzhnllmfqcdecbzxxuqwxabdyldaguydhgtombytrzgfyyqecqmjspfhjqabjzhlprvpqydsyjqzhuagrhussfxqlvlmgzfasmgfhijgbqcqnywrjbgiyjbddbectefvohbbrebasilnsfdcknnbwvnblipsqfsgmmesmcjubrvsjnbrjmrxlwpspniurddnysqmzuonctjagunxnnjflfmcyycppgbzwajfzystcqbdviyebxwpaysfausoxcxttaksufmixjtbdmtyhiobecpguinmspsmxtaiwgvumlqreynykmyuruvyvmfonsmwdlcgvpzxffpfwkejmsjuucxlhdbadspjkbvncywagybthhtfduappnsyuotksqmjzdowygrrxzzfwfebehwaxcxbgtrtbspqasyytoyjasvifonfyqaghlenxvikabldcbhfgattnwltqyfbyhfnidxjambtcragebuuqaplnqveiqhyyrplthqqloxgtvmgufgbrpqvtidexvvjwleayzxrvqwimxpwekzcowbmsgxiaakskdebnaljybnejjfkitfzxopqyylncgszssxppetarjpqvkonvzvubxzrtfjpmvnpeyeqvixagcqscnghxmnrmownjmdjzqmmolexgbzitqecxuczcnfojmqwczrnptnocbjfrojbkkscrnvqclnagcejeznuyyoxfcarqypevpjqzxkoxnewbrhvavzhwecwloqpcveqqzcxbxyshnioeaxajtrzhzlmizxshnokvoynsdqddloverzicjntuksmuwciufmiipujhmootsnzbxbzeogulqmknpzbusrctcofcjdnylugjubmycqygcqrthzzlacvgnyrcfkmzlxdsturcywgpreqwpteovyzxualqszoezswjmburgsdufbxfuhszsvscyphvdxtoegygtknowexpxoatduwtdgmkknojpekuzrvbghemjkdjjmjfiszwatkcerinioerwftsmiulegwlxpygurccfvynhjwdgmqcbydnrdlbovsmxygkilmwgtrmjtxusdjwyxcdfqsyhntoxrnkssmlmtppdeayywhdkziiffvpcnmtreayhpdivvybgvzmmwxqjpniqhrdesyddmesvlgqmpcdzxmofzsnefbmwuklpqkxwxkdquvwcguyjarnokzsrannhvseihtdovkblkonzuwztkbkolwoipwqhkgovxbbpkquznngsgldadbifeeohvtlhfpjlhskaowblqkyfzhqlwfkbslvdlrkbfcpdbnmwjrhreyyzteafjlrwdxinjqwrbpzhkedygojaoygaipnoeglnsfsuhncxlrfuueqcezxlapvhzideptdjjgesosghhgaqimhzmzyojamhlriplnehdoreepxsbvlikrvnpsumpiflnxehummshnyppyhknxnumdoaogheaxtupsustpuqkndbygutuwfgglkoaozrxevaabotilxojszcrdyixsejakiabvatvcsshonwzgtsuxoylypautffnpsenhmxnkumaxccsmhisflnkteepzmlegurnmmrtrdhbsfwlojbuklvczttasgdloomggyohbgfytnbdbcdnnjnkfzxpkjrftamseqozfranpzswsmvvfhxriqksotsjoksaqvpusoqthiwzquvxdsrtjpjyuldltjaqeugkmmxsafrqyiiglznggjympmglmsujgrigjhrmnsncjjlsogeofdevwdwtkxyzyflxzccjeslzuotvchzmmultucjpilismctsuvoaamfrcdlhdfclphyranzxiaggaqmiqntatumepwyzhnujfvtoiwylwibermfrbkffcurluvdawpvzxzdifqhywmejuqmkdebxxirnxriytdfnrppvoltetmuejtyrcngfzohxtebinybhpvoojksizqvlcgcujiewcmsqxpbfnirbmgjvbppghcmdnornduhzrojmrwkztpxrviyzequoicywkyqcdifgmizcmdwmqnaatbkowqtolikdmptieouutoilmruhbuoyplvkaxqdgmplnqpozkffcugwdpmayzejybojvoqlzfaktaiaqvcfurlhqntfprradibjhbedgwjwcediyezkgockpyrsaldfnlqnwmwqmuntfxwscwswdjhpqhydhgfijqwfeouivruxwdokcikdyyfgpgwhysxrqqaqxkoyuscmbluimeneoqbctuilltopgkudnunyzyxnhbpglkxlkxqvzfbktxuiocjcjfchkoyxzlgijdmehhorzyckfibgvrrmonhkswxzenugexosdyeljkiebeapmaacxrtrquzomlrbvtnjjoaruiwerkfotyddvpglherdmpepewqfkildmhqieewxewiqxaijnjtelanilyzzuljjrpbsprzbycbwhyxnyinbqmyjjcpwioaijukrnbxlhxndsowbnzstnfzrxrrgtpcuchblaobjemtzjwoausdkpqhwfgtobjlcfzrgxlvjpuxriipenygpbadlyxklljvqwytfmbjlxvregeinuvajsrtoivkmmcrtoxaitchhveqtkirydhkhwslzksbemgdnligeetxtcngugxwrtxsbaixcihtwtgpicfzjeawmihjakbwlissvunmseghocjasmeckmbmlnllczqotflfxuimvznvcbihpjbxdglwyhkzdtduufexqbfbljfzyvrfadabkgdcaugndnqbqmejlhfrvgxzjzzoetzllqeefkaubbventsawlethbqquuwkaosmsrekyluggoxhnhfrxaevrcwmekyvamxmhgprdtuhzrewhhqltiateotxslspidnieoorfmdygjawdalpbnodcbyngadqrifvuhxnqsufqhlhzwserodxspcawrmeewjtstrcfzkiibnpxaengffmwmwydjtdvtbhdpzvcifoztbdenvprxjesuwfbdljvzwpquvfprhqpxiuqmoyogvinslnfyekwliwuzkhjuvlfzjynwfaxrvxulzjibjndvhyohnjkeckxjmoonedlcvdbepjtrjoothelvmoxjmbplroomdpc";

	char* a = arr;

	printf(repeatLimitedString(a, 5081));
	return 0;
}