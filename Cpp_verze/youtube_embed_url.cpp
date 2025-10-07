// youtube_embed_url

#include <iostream>
#include <fstream>

using namespace std;

// deklarace prommenych
string out1 = "https://www.youtube.com/embed/", out2, out3, out4, out5;
string str; // pouze pomocna promenna
string cas1, cas2, url;
string run_filename = "youtube_embed_url";
int h1, m1, s1, h2, m2, s2;
unsigned int v1, v2; // rozsah typu unsigned int je 0 az ?
int d_url, d2_url;
string str_v1, str_v2, video_ID;
string filename = "output.txt";
//

int main(int argc, char** argv) {	
//cout<<argc<<endl;
if ( argc != 4 ) { // jestlize celkovy pocet argumentu neni prave 4 ( 0, 1, 2, 3 )
// argv[0] je nazev spusteneho souboru tedy "youtube_embed_url.exe"
// argv[1] je start cas, argv[2] stop cas a nakonec argv[3] je url youtube videa
cout<<"pouziti:"<<endl;
cout<<run_filename<<" 01:11:35 01:22:59 https://youtube.com/2PNY4RxISKw"<<endl;
cout<<run_filename<<"    ^-start   ^-stop        ^-youtube video url "<<endl<<endl;
cout<<run_filename<<" 00:00:00 01:22:59 https://youtu.be/2PNY4RxISKw"<<endl;
cout<<run_filename<<"    ^-pro prehrani videa od uplneho zacatku pouzit toto"<<endl<<endl;
cout<<"vysledky se vzdy zapisuji do souboru "<<'"'<<filename<<'"'<<endl;

system("pause");
return 0;
}

cas1 = argv[1];
cas2 = argv[2];
url = argv[3];
//cout<<cas1<<endl;
//cout<<cas2<<endl;
//cout<<url<<endl;

// substituce arg[1] a rag[2] na jednotlivosti a prevod do datoveho typu int
h1 = stof(cas1.substr (0,2)); // funkce stof() - prevede sting na int (neni potreba zadne #incude <> )
//cout<<h1<<endl;

m1 = stof(cas1.substr (3,2));
//cout<<m1<<endl;

s1 = stof(cas1.substr (6,2));
//cout<<s1<<endl;

// totez pro argv[2]
h2 = stof(cas2.substr (0,2)); // substr() je v Cpp funkce pro subtituci datove promenne typu string - cas2
//cout<<h2<<endl;

m2 = stof(cas2.substr (3,2));
//cout<<m2<<endl;

s2 = stof(cas2.substr (6,2));
//cout<<s2<<endl;

// vypocet vterin z - hh:mm:ss, cas start
v1 = (( h1 * 3600 + m1 * 60 + s1));
//cout<<v1<<endl;

// vypocet vterin z - hh:mm:ss, cas stop
v2 = (( h2 * 3600 + m2 * 60 + s2));
//cout<<v2<<endl;

// zpracovani argv[3], url youtube videa
url = argv[3];
//cout<<url<<endl;
//len = str3.size();
//len_2 = sizeof(str3);
d_url = url.size();
//cout<<d_url<<endl;
d2_url=(( d_url - 11 ));
//cout<<d2_url<<endl;
video_ID = url.substr (d2_url,11);
//cout<<video_ID<<endl;


// zapise vysledky do souboru "output.txt", test read-only
ofstream outFile(filename); // otevreni souboru "output.txt" pro zapis.
if (!outFile) {
cout<<"chyba pri zapisu vysledku do souboru "<<filename<<endl;
cout<<"program bude predcasne ukoncen"<<endl;
system("pause");
return 1; // chybovej navat 1
}

// tisk konecnych vysledku
if ( v1 == 0 ) {
	
// bude pouze parametr &end=
//cout << "pouze end=" << endl;
// https://www.youtube.com/embed/IQrdyTrOUsQ?autoplay=1&mute=1&end=81&vq=large
out2 = out1;
out2 += video_ID;
out2 += "?autoplay=1&mute=1&end=";
// int "v2" prevect do typu stings aby se dalo pricist k "out2"
//string s = to_string(a);
str_v2 = to_string(v2); // (neni potreba zadne #incude <> )
out2 += str_v2;
out2 += "&vq=large"; // tohle tady muze bejt nebo nemusi ( dalsi ukazky moznosti jsou v souborech *.jpg )
cout<<out2<<endl;
/*
stejna adresa ale bez parametru "autoplay" a "mute"
na youtube funguje autoplay videa pouze v rezimu bez zvuku ( asi si nikdo stezoval )
takze jsou dve moznosti a jinak to nejde
moznost 1:
video zacne samo hrat ale pouze bez zvuku a je nutno kliknoy na ikonu reproduktoru a zvuk
si sam zapnot, bez parametu mute=1 nefunguje parametr autoplay=1
mute=0 je nesmysl davat protoze to je na default
a parametr autoplay ma na default (cili paklize se z nici nehejbe) hodnotu autoplay=0
moznost 2:
vynechat autoplay=1 tim odpadne nutnost mute=1 a video si proste pusti rucne kliknutim
na tlacitko play
a to je vsechno co se stim dat delat cili autoplay=1 samo o sebe bohuzel nefunguje
mam pocit ze kdysi to slo a jak rikam asi si lidi stezovaly ze nakomu neco zacalo
samo od sebe hrat a rvat zvuk do toho, takze tedko to lze pouze takle
udajne je to da nejak obejit v java scriptu ale tim uz jsem se nezabejval protoze
to nebudu potrebovat
*/

// zde tedy totez ale bez autoplay atd. at si potom uzivatel sam vybere co se mu libi vic
out3 = out1;
out3 += video_ID;
out3 += "?end=";
out3 += str_v2;
out3 += "&vq=large";
cout<<out3<<endl;
//zapis dat do souboru output.txt pro tuto cast, tedy pouze parametr end= a start od zacatku videa
outFile<<out2<<endl;
outFile<<out3<<endl;
outFile.close();


} else {
// bude pouze parametr &start=&end=
//cout << "bude start= end=" << endl;
// https://www.youtube.com/embed/IQrdyTrOUsQ?autoplay=1&mute=1&start=60&end=70
out4 = out1;
out4 += video_ID;
out4 += "?autoplay=1&mute=1&start=";
str_v1 = to_string(v1);
out4 += str_v1;
out4 += "&end=";
str_v2 = to_string(v2);
out4 += str_v2;
out4 += "&vq=large";
cout<<out4<<endl;

// zde opet totez ale bez autoplay
out5 = out1;
out5 += video_ID;
out5 += "?start=";
out5 += str_v1;
out5 += "&end=";
out5 += str_v2;
out5 += "&vq=large";
cout<<out5<<endl;

// samotny zapis dat do souboru
outFile<<out4<<endl;
outFile<<out5<<endl;
outFile.close();
}

//a nebo zapis dat do souboru output.txt pro cast start= end=
outFile<<out2<<endl;
outFile<<out3<<endl;
outFile.close();

// info
cout<<endl<<"vysledky byly zapsany do souboru "<<'"'<<filename<<'"'<<endl;

system("pause");
return 0;
}


