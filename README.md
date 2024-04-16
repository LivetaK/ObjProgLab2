KAIP VEIKIA PROGRAMA

Ši programa skaičiuoja studentų galutinį tam tikro kurso balą, naudodama studento pažymius ir egzaminų rezultatus. Programa realizuota su trimis skirtingais konteineriais: vector, deque, list; ir su trejomis skirtingomis strategijomis, todėl galima pasirinkti, kaip norima dirbti. Galima duomenis įvedinėti ranka, galima ir liepti programai juos skaityti iš failo. Štai taip veikia paleista programa:

1. Paleidus programą išvedamas klausimas, kaip norima, kad būtų nuskaityti duomenys - ar iš failo, ar įvesti ranka;
2. Jei pasirenkame duomenis įrašyti ranka, išvedamas pasirinkimo meniu: ar įvedinėjame ranka, ar leidžiame programai sugeneruoti pažymius automatiškai, ar norime kad tiek studentų vardai, tiek jų pažymiai būtų generuojami auromatiškai;
3. Jei pasirinkame, kad duomenys būtų skaitomi iš failo svarbu, kad failas būtų įkeltas į tą patį aplanką kartu su programa;
4. Vedant vis naujus duomenis, programa paklaus jai rūpimų klausimų, kurie būtini galutinio balo skaičiavimui;
5. Jei buvo pasirinkta duomenis skaityti iš failo, reiks pasirinkti, ir kur juos išvesti - ar į ekraną, ar į naujai sugeneruotą failą.


PASIRUOŠIMAS


Prieš naudojant programą, reikia atsisiųsti Visual Studio: https://visualstudio.microsoft.com/downloads/ paspaudę "download" būsite nunaviguoti į puslapį, kuriame bus paaiškinta, kaip dirbti su Visual Studio.

Taip pat reikia atsisiųsti CMake, kuris jums paruoš .exe failus, kad galėtumėte iš karto naudoti programą: https://cmake.org/download/ . Atsisiuntę nueikite į komandinę eilute, nunaviguokite į aplanką, kuriame yra šis projektas (naudokite komandą cd ir įrašykište kelią). Tada įveskite "cmake -G "Visual Studio 17 2022" <kelias iki aplanko su projektu>. 



V1.0 TESTAVIMAS

---------------------------------------------------------
Testavimo sistemos parametrai:
![Screenshot 2024-03-22 200611](https://github.com/LivetaK/ObjProgLab/assets/159531709/d4f0758b-1db6-4713-8b33-70aa780d6a02)


*********************************************************

PIRMA TESTAVIMO DALIS 

*********************************************************

REZULTATAI SU DEQUE:

Tyrimas su 1 000 studentu:


![Screenshot 2024-03-22 193720](https://github.com/LivetaK/ObjProgLab/assets/159531709/d73580b1-d45b-4575-963f-9537d4607b5e)
![Screenshot 2024-03-22 193741](https://github.com/LivetaK/ObjProgLab/assets/159531709/7eb628b8-1946-41f3-bc18-5b13c02f67d3)
![Screenshot 2024-03-22 193755](https://github.com/LivetaK/ObjProgLab/assets/159531709/7b8fdd0a-a45b-45e9-946c-7aeee2fff358)


Tyrimas su 10 000 studentu:


![Screenshot 2024-03-22 193934](https://github.com/LivetaK/ObjProgLab/assets/159531709/d34605c5-441e-42a9-ba30-86c19b8bed03)
![Screenshot 2024-03-22 193948](https://github.com/LivetaK/ObjProgLab/assets/159531709/cf4f0ffc-b2cb-4972-8def-8a2b6428b77d)
![Screenshot 2024-03-22 194001](https://github.com/LivetaK/ObjProgLab/assets/159531709/7980829e-1e05-4041-b4ef-ee4c6489c634)


Tyrimas su 100 000 studentu:


![Screenshot 2024-03-22 194102](https://github.com/LivetaK/ObjProgLab/assets/159531709/1a944064-1ecd-443f-aaf8-fee9159f1089)
![Screenshot 2024-03-22 194049](https://github.com/LivetaK/ObjProgLab/assets/159531709/adac0415-a1ed-49c9-a755-defffe935524)
![Screenshot 2024-03-22 194036](https://github.com/LivetaK/ObjProgLab/assets/159531709/c8850570-dd49-4629-8dcd-f65a0be861bb)


Tyrimas su 1 000 000 studentu:


![Screenshot 2024-03-22 194246](https://github.com/LivetaK/ObjProgLab/assets/159531709/e5993863-2626-4d6d-9f58-e8a0fbf8bfe3)
![Screenshot 2024-03-22 194219](https://github.com/LivetaK/ObjProgLab/assets/159531709/10785fe1-abe6-46a8-bc56-afb838e530e3)
![Screenshot 2024-03-22 194154](https://github.com/LivetaK/ObjProgLab/assets/159531709/ef02d105-1078-4319-9519-ab9cd9d8dd68)


Tyrimas su 10 000 000 studentu:


![Screenshot 2024-03-22 195155](https://github.com/LivetaK/ObjProgLab/assets/159531709/cc12e404-e535-4f0a-a61e-8e2eaacfd789)
![Screenshot 2024-03-22 194929](https://github.com/LivetaK/ObjProgLab/assets/159531709/7fbd1708-e8f1-4373-a125-9a3d1bccc989)
![Screenshot 2024-03-22 194610](https://github.com/LivetaK/ObjProgLab/assets/159531709/942696f1-0245-445e-a311-575fc6ed92d9)


REZULTATAI SU VECTORS:


Tyrimas su 1 000 studentu:


![Screenshot 2024-03-22 202532](https://github.com/LivetaK/ObjProgLab/assets/159531709/9adf0145-5704-4ae6-9c14-0b44ff7c1e65)
![Screenshot 2024-03-22 202508](https://github.com/LivetaK/ObjProgLab/assets/159531709/0bcf6a61-8ead-4fc3-9a1c-9d4f7a6328e6)
![Screenshot 2024-03-22 202420](https://github.com/LivetaK/ObjProgLab/assets/159531709/cbbacf13-4043-4a8f-9cd3-fd0909df0805)


Tyrimas su 10 000 studentu:


![Screenshot 2024-03-22 202802](https://github.com/LivetaK/ObjProgLab/assets/159531709/76e010d2-a36a-42d3-85bf-c4407857d408)
![Screenshot 2024-03-22 202751](https://github.com/LivetaK/ObjProgLab/assets/159531709/36b8f1c9-42f5-4b64-bc71-b832dc628086)
![Screenshot 2024-03-22 202740](https://github.com/LivetaK/ObjProgLab/assets/159531709/b82b1ddf-c22f-4247-9020-5b06669c7b43)


Tyrimas su 100 000 studentu:


![Screenshot 2024-03-22 202908](https://github.com/LivetaK/ObjProgLab/assets/159531709/f15b92b1-f3bd-426a-88c9-41a543101f6a)
![Screenshot 2024-03-22 202853](https://github.com/LivetaK/ObjProgLab/assets/159531709/810d63b9-c0c1-447c-90cd-7fde768b86a6)
![Screenshot 2024-03-22 202836](https://github.com/LivetaK/ObjProgLab/assets/159531709/53835662-8c9a-41b1-9186-c05f6bf056a7)


Tyrimas su 1 000 000 studentu:


![Screenshot 2024-03-22 203118](https://github.com/LivetaK/ObjProgLab/assets/159531709/366973b0-c619-47fa-925c-58e5378598b9)
![Screenshot 2024-03-22 203058](https://github.com/LivetaK/ObjProgLab/assets/159531709/59b781c7-a875-4884-baa2-33b88053d1c3)
![Screenshot 2024-03-22 203034](https://github.com/LivetaK/ObjProgLab/assets/159531709/ec365ec8-85a9-4af9-8c7b-4a1de5ff2f4a)


Tyrimas su 10 000 000 studentu:


![Screenshot 2024-03-22 203755](https://github.com/LivetaK/ObjProgLab/assets/159531709/ab7cabbc-190a-4a82-b800-ee652a18a40e)
![Screenshot 2024-03-22 203543](https://github.com/LivetaK/ObjProgLab/assets/159531709/9e0d67e6-a1d0-45dc-a34d-233f473841c6)
![Screenshot 2024-03-22 203335](https://github.com/LivetaK/ObjProgLab/assets/159531709/c2d1ab03-a234-41c2-8783-6fcc3bfa3590)



REZULTATAI SU LIST:


Tyrimas su 1 000 studentu:


![Screenshot 2024-03-23 103608](https://github.com/LivetaK/ObjProgLab/assets/159531709/8dedfbd8-d38e-4384-84b2-6983ce989fa9)
![Screenshot 2024-03-23 103554](https://github.com/LivetaK/ObjProgLab/assets/159531709/9f481514-bff8-45bc-aef7-b068059a8b63)
![Screenshot 2024-03-23 103541](https://github.com/LivetaK/ObjProgLab/assets/159531709/93b86af4-836d-4be8-9c77-c418a56d0b12)


Tyrimas su 10 000 studentu:


![Screenshot 2024-03-23 103718](https://github.com/LivetaK/ObjProgLab/assets/159531709/92a66ace-ee17-43fe-ac85-a20256135955)
![Screenshot 2024-03-23 103656](https://github.com/LivetaK/ObjProgLab/assets/159531709/c854b266-484a-4091-b577-741388df841d)
![Screenshot 2024-03-23 103637](https://github.com/LivetaK/ObjProgLab/assets/159531709/8db1afe2-8b68-4dcb-9e29-13f014095603)


Tyrimas su 100 000 studentu:

![Screenshot 2024-03-23 103826](https://github.com/LivetaK/ObjProgLab/assets/159531709/73dc5e46-d19c-4a51-a211-377b53d11e34)
![Screenshot 2024-03-23 103810](https://github.com/LivetaK/ObjProgLab/assets/159531709/a0c7e619-a901-4250-bd00-f83555e77f30)
![Screenshot 2024-03-23 103752](https://github.com/LivetaK/ObjProgLab/assets/159531709/afec6367-7e96-47b0-acca-e59abb2b8e27)


Tyrimas su 1 000 000 studentu:


![Screenshot 2024-03-23 104013](https://github.com/LivetaK/ObjProgLab/assets/159531709/be6ea2a8-dc7a-40f5-98a3-70b399a86038)
![Screenshot 2024-03-23 103944](https://github.com/LivetaK/ObjProgLab/assets/159531709/0b849786-c89c-4990-a37b-a58ceecbfb8f)
![Screenshot 2024-03-23 103915](https://github.com/LivetaK/ObjProgLab/assets/159531709/352ee267-6f07-42b0-928b-7fa12571d266)


Tyrimas su 10 000 000 studentu:


![Screenshot 2024-03-23 104915](https://github.com/LivetaK/ObjProgLab/assets/159531709/dd6cb089-f973-4540-bcc7-e091ff385b97)
![Screenshot 2024-03-23 104618](https://github.com/LivetaK/ObjProgLab/assets/159531709/739a9e1b-16cc-4bfc-8bc2-59bb6a59947b)
![Screenshot 2024-03-23 104307](https://github.com/LivetaK/ObjProgLab/assets/159531709/9823b12f-94e7-4820-ba39-a7c58038b770)



Rezultatu apibendrinimas ir palyginimas:


![Screenshot 2024-03-23 111932](https://github.com/LivetaK/ObjProgLab/assets/159531709/40d9c592-d1a6-4c26-96ed-116df5bf7ade)


*********************************************************

ANTRA TESTAVIMO DALIS 

*********************************************************


1 STRATEGIJA:


vectors


![Screenshot 2024-03-27 150831](https://github.com/LivetaK/ObjProgLab/assets/159531709/0dbc0853-8efc-4b52-80e3-cfe365187297)
![Screenshot 2024-03-27 150633](https://github.com/LivetaK/ObjProgLab/assets/159531709/8a801c62-0d5e-4252-ba31-b794a6f419cb)
![Screenshot 2024-03-27 150607](https://github.com/LivetaK/ObjProgLab/assets/159531709/fd3f67a3-acd2-4eaa-a81d-43a333264c77)
![Screenshot 2024-03-27 150551](https://github.com/LivetaK/ObjProgLab/assets/159531709/542afe0e-db4d-443b-a873-ccdb0c38a07d)
![Screenshot 2024-03-27 150528](https://github.com/LivetaK/ObjProgLab/assets/159531709/770d5cee-7dbd-4317-af8e-22dc9c723689)


deque


![Screenshot 2024-03-27 145719](https://github.com/LivetaK/ObjProgLab/assets/159531709/3c9e6607-26c9-42b9-94e5-6e143cb9dc2f)
![Screenshot 2024-03-27 145507](https://github.com/LivetaK/ObjProgLab/assets/159531709/6537cfae-4fa6-4279-af32-6a5f4f54eb86)
![Screenshot 2024-03-27 145434](https://github.com/LivetaK/ObjProgLab/assets/159531709/668e8d56-3543-4834-8b64-04965da3fb6b)
![Screenshot 2024-03-27 145411](https://github.com/LivetaK/ObjProgLab/assets/159531709/46dd6cda-b853-45ea-900a-f06b3318102a)
![Screenshot 2024-03-27 145350](https://github.com/LivetaK/ObjProgLab/assets/159531709/379662e7-350b-44f7-988e-9ae927ab1426)


list


![Screenshot 2024-03-27 150348](https://github.com/LivetaK/ObjProgLab/assets/159531709/35a25829-8431-4ec8-bb27-470b9c0e2cfe)
![Screenshot 2024-03-27 150122](https://github.com/LivetaK/ObjProgLab/assets/159531709/40b216cb-ddb0-44f4-8232-830d8366da1e)
![Screenshot 2024-03-27 150050](https://github.com/LivetaK/ObjProgLab/assets/159531709/e03f4107-4cab-4333-a04b-1f62506a90bd)
![Screenshot 2024-03-27 150029](https://github.com/LivetaK/ObjProgLab/assets/159531709/2a9e6ed1-571a-4b19-a43c-12c6196a2902)
![Screenshot 2024-03-27 150011](https://github.com/LivetaK/ObjProgLab/assets/159531709/ca66ffc2-0d03-46a4-a85d-c888bc1e1d69)



apibendrintai:


![Screenshot 2024-03-27 151250](https://github.com/LivetaK/ObjProgLab/assets/159531709/291e1fbc-3b37-4c3c-8a3f-09bf16624409)



2 STRATEGIJA


vectors


![Screenshot 2024-03-27 175938](https://github.com/LivetaK/ObjProgLab/assets/159531709/955732f5-e331-496f-9c31-96f71954c5d2)
![Screenshot 2024-03-27 175748](https://github.com/LivetaK/ObjProgLab/assets/159531709/c5c5c0f9-4aa6-42a9-a31f-ec42d64790cb)
![Screenshot 2024-03-27 175715](https://github.com/LivetaK/ObjProgLab/assets/159531709/1a0687ef-b20c-4a89-985a-732ac14989d7)
![Screenshot 2024-03-27 175656](https://github.com/LivetaK/ObjProgLab/assets/159531709/1efb0e1a-71d7-4cf7-854e-39ca03790d2e)
![Screenshot 2024-03-27 175637](https://github.com/LivetaK/ObjProgLab/assets/159531709/4f63d614-3460-4cd9-8775-7702b04cece9)


deque


![Screenshot 2024-04-04 193250](https://github.com/LivetaK/ObjProgLab/assets/159531709/04b76f80-3de6-4d96-b286-a18c93a76bce)
![Screenshot 2024-04-04 193036](https://github.com/LivetaK/ObjProgLab/assets/159531709/293ede4c-9771-4599-8b10-7077ddb4a1d9)
![Screenshot 2024-04-04 193004](https://github.com/LivetaK/ObjProgLab/assets/159531709/2f2dbfef-d692-4bea-9291-cfaf5f9ef144)
![Screenshot 2024-04-04 192946](https://github.com/LivetaK/ObjProgLab/assets/159531709/7de91b0a-7592-4b2b-9b38-712f32de4363)
![Screenshot 2024-04-04 192925](https://github.com/LivetaK/ObjProgLab/assets/159531709/08ec5fb4-c3cc-47e7-b870-34d5046d70ae)


list


![Screenshot 2024-04-04 194435](https://github.com/LivetaK/ObjProgLab/assets/159531709/c4fb6311-2214-43d0-b964-dcf8cefa7422)
![Screenshot 2024-04-04 194220](https://github.com/LivetaK/ObjProgLab/assets/159531709/faad14f9-9bee-4d15-a081-cb4c764b3580)
![Screenshot 2024-04-04 194154](https://github.com/LivetaK/ObjProgLab/assets/159531709/60349ceb-6122-4e7c-887e-9081be42414d)
![Screenshot 2024-04-04 194139](https://github.com/LivetaK/ObjProgLab/assets/159531709/87e185ff-a763-4e12-b5f4-20ce51c64a51)
![Screenshot 2024-04-04 194115](https://github.com/LivetaK/ObjProgLab/assets/159531709/ed371b5c-33a1-41f9-9bb6-b49ae227fac9)


apibendrintai:


![Screenshot 2024-04-04 201653](https://github.com/LivetaK/ObjProgLab/assets/159531709/229c624b-f8bc-422f-85d5-b3973b72e758)



3 STRATEGIJA


Kadangi pradiėje programoje buvo naudota std :: partition, niekas nebuvo pakeista, tik studentų konteinerio trynimas iškeltas iš funkcijos:


vectors


![Screenshot 2024-04-04 212903](https://github.com/LivetaK/ObjProgLab/assets/159531709/8dbf1de8-e9a7-486c-a84e-fd8626da18bf)
![Screenshot 2024-04-04 212715](https://github.com/LivetaK/ObjProgLab/assets/159531709/5def58b2-6e7b-4907-8be2-e3bf8794a525)
![Screenshot 2024-04-04 212651](https://github.com/LivetaK/ObjProgLab/assets/159531709/7b10b6bc-0ed5-4eaa-8c38-27dc86980398)
![Screenshot 2024-04-04 212634](https://github.com/LivetaK/ObjProgLab/assets/159531709/1ff7d5ca-2676-4f82-a91f-555c11011113)
![Screenshot 2024-04-04 212602](https://github.com/LivetaK/ObjProgLab/assets/159531709/8a4b8613-dec6-4a3e-8c42-8f2d5c1c5e43)


deque


![Screenshot 2024-04-04 214156](https://github.com/LivetaK/ObjProgLab/assets/159531709/f76304c3-5ae9-4cc2-bbbb-2a46e2553a4f)
![Screenshot 2024-04-04 213943](https://github.com/LivetaK/ObjProgLab/assets/159531709/e95ca626-586b-452b-957f-58ccf45c8e2d)
![Screenshot 2024-04-04 213918](https://github.com/LivetaK/ObjProgLab/assets/159531709/51d9af67-467f-49ea-9496-52395d29172d)
![Screenshot 2024-04-04 213905](https://github.com/LivetaK/ObjProgLab/assets/159531709/1d5f6e29-89a0-49eb-a443-86a993cd7643)
![Screenshot 2024-04-04 213850](https://github.com/LivetaK/ObjProgLab/assets/159531709/aad674ce-cea8-4b71-890f-0e3fde089046)


list


![Screenshot 2024-04-04 213637](https://github.com/LivetaK/ObjProgLab/assets/159531709/5d3e3619-eed1-4e90-a3b9-85cb202ee5da)
![Screenshot 2024-04-04 213358](https://github.com/LivetaK/ObjProgLab/assets/159531709/da9070c6-b1dc-4434-8edd-250e06cde8d5)
![Screenshot 2024-04-04 213331](https://github.com/LivetaK/ObjProgLab/assets/159531709/8aa98ef2-cf54-4570-86ee-7196d002dac1)
![Screenshot 2024-04-04 213316](https://github.com/LivetaK/ObjProgLab/assets/159531709/f8184784-6013-4d79-80ed-aac22e4d9fb9)
![Screenshot 2024-04-04 213301](https://github.com/LivetaK/ObjProgLab/assets/159531709/76735f9c-666a-47b4-b071-7d4683e22688)


apibendrintai:


![Screenshot 2024-04-04 214629](https://github.com/LivetaK/ObjProgLab/assets/159531709/463c11c6-b273-4e0b-b3f5-8d574a4b5d30)






