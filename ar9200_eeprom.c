#include <stdio.h>
#include <cstring>
#define FILE_SIZE 64*1024

struct B {
  unsigned char Unknown1[4096]; //Initial Offset
  unsigned char Magic[2]; //2
  unsigned char charMask[2]; //2
  unsigned char Location[2]; //2
  unsigned char Offset3[2]; //2
  unsigned char Unknown2[512-8];

  unsigned char EPROMDATA[64];
  unsigned char CUSTOMERDATA[64];
  unsigned char EEPROM5ghz[104];
  unsigned char EEPROM2ghz[104];
  unsigned char POWERCALIBRATION[12];
  unsigned char POWERCALIBRATIONDATA5ghz[960];
  unsigned char POWERCALIBRATIONDATA2ghz[480]; 
  // unsigned char TARGETPOWER80211a[40];

  unsigned char TotalBytes[2];
  unsigned char Checksum[2]; 
  unsigned char Version[2];
  unsigned char OpFlags[1];
  unsigned char EepMisc[1];
  unsigned char regDomain[2];

  unsigned char regDomainExt[2];
  unsigned char MAC[6];
  unsigned char rxMask[1];
  unsigned char txMask[1];
  unsigned char rfSilent[2];
  unsigned char blutooth[2];
  unsigned char capabilities[2];
  unsigned char CalibrationVersion[4];

  unsigned char deviceType[1];
  unsigned char pwdclkind[1];
  unsigned char Clk5g[1];
  unsigned char divChain[1];
  unsigned char rxGainType[1];
  unsigned char dacHiPwrMode_5g[1];
  unsigned char openLoopPwrCntl[1];
  unsigned char dacLpMode[1];
  unsigned char txGailType[1];
  unsigned char rcChainMask[1];
  unsigned char desiredScaleCCK[1];
  unsigned char pwrTableOffset[1];
  unsigned char fracN5g[1];
  unsigned char futureBase[21];

  unsigned char TARGETPOWER5GHZ80211nHT20[72];
  unsigned char TARGETPOWER5GHZ80211nHT40[72];
  unsigned char TARGETPOWER2GHZ80211bgCCK[15];
  unsigned char TARGETPOWER2GHZ80211gOFDM[20];
  unsigned char TARGETPOWER2GHZ80211gHT20OFDM[36];
  unsigned char TARGETPOWER2GHZ80211gHT40OFDM[36];
  unsigned char CTLIndex[36];
  unsigned char CTLData[36];


  unsigned char buffer[FILE_SIZE];
};

int currentCounter=4096; 
void PrintHex (char const *type,unsigned char const *c,int len) {
  printf("%x\t%30s \t%i\t",currentCounter,type,len);

  for (int i=0 ; i<len; i++ )
    {
      if (len==-1) {
	printf("%2hhx ", c);
      } else {
	printf("%hhx ", c[i]);
      }
    }
  printf("\n");
  currentCounter=currentCounter+len;

}
short checksum(unsigned char *packet,int packet_len) {
  unsigned short int Cxor = 0;
  for ( int i = 0 ; i < packet_len ; i = i +2 ) {
  unsigned short int trg;
// printf("%i (%i) ",Cxor,trg);
    memcpy(&trg,&packet[i],2);
    Cxor = Cxor ^ trg; //packet[i];
 }
 return Cxor;
}
int main() {

  unsigned char b[FILE_SIZE];
  struct B buffer;
  FILE *f;
  int n=0;

  f = fopen("art.bin", "rb");
  n = fread(&b, FILE_SIZE, 1, f);
  memcpy(&buffer,&b,FILE_SIZE);
  fclose(f);

  PrintHex("Magic",buffer.Magic,sizeof(buffer.Magic));
  PrintHex("charMask",buffer.charMask,sizeof(buffer.charMask));
  PrintHex("Location",buffer.Location,sizeof(buffer.Location));
  PrintHex("Offset3",buffer.Offset3,sizeof(buffer.Offset3));
  PrintHex("Unknown2",buffer.Unknown2,sizeof(buffer.Unknown2));

  PrintHex("EPROMDATA",buffer.EPROMDATA,sizeof(buffer.EPROMDATA));
  PrintHex("CUSTOMERDATA",buffer.CUSTOMERDATA,sizeof(buffer.CUSTOMERDATA));
  PrintHex("EEPROM5ghz",buffer.EEPROM5ghz,sizeof(buffer.EEPROM5ghz));
  PrintHex("EEPROM2ghz",buffer.EEPROM2ghz,sizeof(buffer.EEPROM2ghz));
  PrintHex("POWERCALIBRATION",buffer.POWERCALIBRATION,sizeof(buffer.POWERCALIBRATION));
  PrintHex("POWERCALIBRATIONDATA5ghz",buffer.POWERCALIBRATIONDATA5ghz,sizeof(buffer.POWERCALIBRATIONDATA5ghz));
  PrintHex("POWERCALIBRATIONDATA2ghz",buffer.POWERCALIBRATIONDATA2ghz,sizeof(buffer.POWERCALIBRATIONDATA2ghz));

  PrintHex("TotalBytes",buffer.TotalBytes,sizeof(buffer.TotalBytes));
  PrintHex("Checksum",buffer.Checksum,sizeof(buffer.Checksum));
  PrintHex("Version",buffer.Version,sizeof(buffer.Version));
  PrintHex("OpFlags",buffer.OpFlags,sizeof(buffer.OpFlags));
  PrintHex("EepMisc",buffer.EepMisc,sizeof(buffer.EepMisc));
  PrintHex("regDomain",buffer.regDomain,sizeof(buffer.regDomain));
  PrintHex("regDomainExt",buffer.regDomainExt,sizeof(buffer.regDomainExt));
  PrintHex("MAC",buffer.MAC,sizeof(buffer.MAC));
  PrintHex("rxMask",buffer.rxMask,sizeof(buffer.rxMask));
  PrintHex("txMask",buffer.txMask,sizeof(buffer.txMask));
  PrintHex("rfSilent",buffer.rfSilent,sizeof(buffer.rfSilent));
  PrintHex("blutooth",buffer.blutooth,sizeof(buffer.blutooth));
  PrintHex("capabilities",buffer.capabilities,sizeof(buffer.capabilities));
  PrintHex("CalibrationVersion",buffer.CalibrationVersion,sizeof(buffer.CalibrationVersion));
  PrintHex("deviceType",buffer.deviceType,sizeof(buffer.deviceType));
  PrintHex("pwdclkind",buffer.pwdclkind,sizeof(buffer.pwdclkind));
  PrintHex("Clk5g",buffer.Clk5g,sizeof(buffer.Clk5g));
  PrintHex("divChain",buffer.divChain,sizeof(buffer.divChain));
  PrintHex("rxGainType",buffer.rxGainType,sizeof(buffer.rxGainType));
  PrintHex("dacHiPwrMode_5g",buffer.dacHiPwrMode_5g,sizeof(buffer.dacHiPwrMode_5g));
  PrintHex("openLoopPwrCntl",buffer.openLoopPwrCntl,sizeof(buffer.openLoopPwrCntl));
  PrintHex("dacLpMode",buffer.dacLpMode,sizeof(buffer.dacLpMode));
  PrintHex("txGailType",buffer.txGailType,sizeof(buffer.txGailType));
  PrintHex("rcChainMask",buffer.rcChainMask,sizeof(buffer.rcChainMask));
  PrintHex("desiredScaleCCK",buffer.desiredScaleCCK,sizeof(buffer.desiredScaleCCK));
  PrintHex("pwrTableOffset",buffer.pwrTableOffset,sizeof(buffer.pwrTableOffset));
  PrintHex("fracN5g",buffer.fracN5g,sizeof(buffer.fracN5g));
  PrintHex("futureBase",buffer.futureBase,sizeof(buffer.futureBase));

  PrintHex("TARGETPOWER5GHZ80211nHT20",buffer.TARGETPOWER5GHZ80211nHT20,sizeof(buffer.TARGETPOWER5GHZ80211nHT20));
  PrintHex("TARGETPOWER5GHZ80211nHT40",buffer.TARGETPOWER5GHZ80211nHT40,sizeof(buffer.TARGETPOWER5GHZ80211nHT40));
  PrintHex("TARGETPOWER2GHZ80211bgCCK",buffer.TARGETPOWER2GHZ80211bgCCK,sizeof(buffer.TARGETPOWER2GHZ80211bgCCK));
  PrintHex("TARGETPOWER2GHZ80211gOFDM",buffer.TARGETPOWER2GHZ80211gOFDM,sizeof(buffer.TARGETPOWER2GHZ80211gOFDM));
  PrintHex("TARGETPOWER2GHZ80211gHT20OFDM",buffer.TARGETPOWER2GHZ80211gHT20OFDM,sizeof(buffer.TARGETPOWER2GHZ80211gHT20OFDM));
  PrintHex("TARGETPOWER2GHZ80211gHT40OFDM",buffer.TARGETPOWER2GHZ80211gHT40OFDM,sizeof(buffer.TARGETPOWER2GHZ80211gHT40OFDM));
  PrintHex("CTLIndex",buffer.CTLIndex,sizeof(buffer.CTLIndex));
  PrintHex("CTLData",buffer.CTLData,sizeof(buffer.CTLData));


  //Possibly BIGEDIAN vs LITTLEDIAN
  int Length=0;
  memcpy(&Length,buffer.TotalBytes,2);

  //Start may not be 1900
  short c=checksum(b+1900,Length);

  unsigned char cc[2];
  memcpy(&cc,&c,2);
  PrintHex("checksum test", cc,sizeof(cc));

  //   printf("Mask: %x\n",buffer.Mask);
  //  printf("Location: %x\n",buffer.Location);
  // printf("Offset: %x\n",buffer.Offset3);
  // printf("---------------\n");
  //PrintHex(buffer.futureBase,21);

  //  printf("Offset: %x\n",buffer.Magic);
 
}
