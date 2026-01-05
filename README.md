# Bite & Delight 🍔🍕🥤
## Milestone 0
### Descriere
Bite & Delight este un joc de tip Fast Food Tycoon, inspirat din celebra serie Papa’s Games. Jucătorul administrează un restaurant mixt de fast food, unde poate crea și vinde diverse produse – pizza, burgeri, snacks și băuturi – gestionând meniurile și comenzile clienților.

Proiectul este realizat în C++, cu accent pe programarea orientată pe obiecte (OOP) și poate fi extins ulterior cu interfață grafică sau funcționalități suplimentare.

## Milestone 1

#### 1 ✅) definirea a minim 3-4 clase folosind compunere cu clasele definite de voi; moștenirile nu se iau în considerare aici  
Am stabilit fundația proiectului prin crearea a patru clase esențiale pentru mecanica jocului:  
   a) `FoodItem` (`FoodItem.h / FoodItem.cpp`) - Produs  
   b) `Order` (`Order.h / Order.cpp`) - Comanda  
   c) `Player` (`Player.h / Player.cpp`) - Jucator/Administrator  
   d) `Customer` (`Customer.h/ Customer.cpp`) - Client  
   Aceste clase sunt interconectate folosind principiul compunerii (relația "has-a"), asigurând o arhitectură curată, decuplată și o separare clară a responsabilităților:  
   a) `Player` are o coadă (`std::queue`) de obiecte `Order`.  
   b) `Customer` are un obiect `Order` (pe care îl generează aleatoriu).  
   c) `Order` are un vector (`std::vector`) de obiecte `FoodItem`.  
   
#### 2 ✅)constructori de inițializare cu parametri pentru fiecare clasă  
Am implementat constructori de inițializare cu parametru pentru toate cele patru clase. Aceștia asigură inițializarea corectă și completă a obiectelor la creare.  
  a) `FoodItem`: Primește `id`, `name`, `price`, și `type` (pentru a defini un produs unic).  
  b) `Order`: Primește `id`, `nivelul de difficulty`, `maxDuration` (durata maximă) și lista de `FoodItem-uri` (conținutul comenzii).  
  c) `Player`: Primește `name` și `balance` (soldul inițial).  
  d) `Customer`: Primeste `name` și `Order` sau, alternativ, meniul `(std::vector<FoodItem>)` din care își generează automat o comandă.  
  
#### 3 ✅)pentru o aceeași (singură) clasă: constructor de copiere, operator= de copiere, destructor  
   Pentru a asigura un management corect și sigur al resurselor obiectelor, am implementat toate acestea pentru clasa `Customer`.  
   
   a)Constructor de Copiere: `Customer(const Customer& alt)`  
   b)Operator de Atribuire (operator=): `Customer& operator=(const Customer& other)`  
   c)Destructor: `~Customer()`  
   
#### 4 ✅) implementarea a minim 3 funcții membru publice pentru funcționalități netriviale specifice temei alese, dintre care cel puțin 1-2 funcții mai complexe
   Am depășit cerința minimă, implementând multiple funcții publice cu logică de business specifică temei, care nu sunt simple operații get/set sau add/delete.  

   `Customer::generateRandomOrder()` (Funcție Complexă): Această funcție statică nu doar creează o comandă, ci folosește logică de probabilitate (std::rand() % 100) pentru a determina dificultatea, numărul de produse și durata comenzii (maxDuration). De asemenea, selectează aleatoriu produse dintr-un `std::vector<FoodItem>` (meniul) pentru a compune comanda.  

   `Order::calc() const`: O funcție netrivială de calcul care iterează prin std::vector<FoodItem> pentru a calcula suma de bază. Ulterior, aplică logică de business, modificând prețul total pe baza unui multiplicator (ex: * 1.15f sau * 1.30f) în funcție de membrul difficulty (Medium/Hard).  

   `Order::hasExpired()` const: O funcție de validare care utilizează biblioteca std::chrono. Calculează diferența dintre timpul curent (system_clock::now()) și timestamp-ul comenzii, comparând durata scursă cu maxDuration pentru a determina dacă comanda a expirat.    

   `Player::finishOrder()` (Funcție Foarte Complexă): Aceasta este cea mai complexă funcție din proiect, gestionând logica centrală de recompensă. Ea folosește std::chrono pentru a calcula timeRatio (procentajul de timp scurs față de cel maxim). Pe baza acestui raport, aplică o logică condițională complexă (ex: timeRatio < 0.3f) pentru a determina bacșișul (tips), care este apoi adăugat la balanța (balance) jucătorului.  

#### 5✅ ) scenariu de utilizare cu sens a claselor definite    
   Am implementat un scenariu de utilizare în main.cpp pentru a demonstra funcționalitatea completă a sistemului și corectitudinea implementării OOP.  

   Testare Unitară: main-ul a fost structurat folosind funcții de testare dedicate pentru fiecare clasă (`testFoodItem()`, `testOrder()`, `testPlayer()`, `testCustomer()`). Aceste funcții verifică individual fiecare funcție publică:    

   Toți constructorii (impliciți, parametrici).  

   Copiere/operator =/destructori (`Customer(const Customer&)` și `operator=`).  

   Toți getterii, setterii și operatorii <<.  

   Test de Integrare (Scenariu "cu sens"): Funcția `testFullScenario()` simulează un flux real de joc. Aceasta integrează toate clasele: un Customer aleatoriu își generează comanda, o trimite Player-ului, Player-ul așteaptă un timp simulat (folosind `std::this_thread::sleep_for`) și apoi finalizează comanda, calculând corect bacșișul (tips).  

   tastatura.txt: Deoarece proiectul nu necesită citire de la `std::cin` (datele sunt generate procedural sau hardcodate pentru testare), fișierul `tastatura.txt` a fost lăsat gol, conform cerinței.    

   Output-ul consolei (vizibil în Actions pe GitHub) demonstrează că toate funcțiile, inclusiv logica complexă de timp și copiere, funcționează conform așteptărilor.  
#### 6 ✅) minim 50-55% din codul propriu să fie C++, .gitattributes configurat corect  
#### 7 ✅) tag de git: de exemplu v0.1  
#### 8 ✅) serviciu de integrare continuă (CI) cu toate bifele; exemplu: GitHub Actions  

## Milestone 2   
#### 1 ✅) separarea codului din clase în .h (sau .hpp) și .cpp   
#### 2 ✅) moșteniri:   
   #####a ✅) minim o clasă de bază și 3 clase derivate din aceeași ierarhie   
    Clasă de bază: WorkStation   
    Clase derivate:   
    OrderStation  
    GrillStation  
    BuildStation  
    ServeStation   
    ##### b ✅) ierarhia trebuie să fie cu bază proprie, nu derivată dintr-o clasă predefinită   
    WorkStation nu derivă din clase predefinite (STL / SFML)  
    ##### c✅) funcții virtuale (pure) apelate prin pointeri de bază din clasa care conține atributul de tip pointer de bază  
      `std::vector<std::unique_ptr<WorkStation>> stations;` in clasa `Restaurant`  
    ##### d) minim o funcție virtuală va fi specifică temei (i.e. nu simple citiri/afișări sau preluate din biblioteci i.e. draw/update/render)  
     `processAction([[maybe_unused]]ActionType action,
                           [[maybe_unused]]Ingredient* ingredient,
                           Order& order,
                           Player& player)`  
    ##### e ✅) constructori virtuali (clone): sunt necesari, dar nu se consideră funcții specifice temei  
    Am adaugat clasei `Workstation` constructor virtual `clone`.  
    ##### f ✅) afișare virtuală, interfață non-virtuală  
    ##### d ✅) apelarea constructorului din clasa de bază din constructori din derivate  
    Toate clasele derivate apelează explicit constructorul `WorkStation`.  
    ##### f ✅) clasă cu atribut de tip pointer la o clasă de bază cu derivate; aici apelați funcțiile virtuale prin pointer de bază, eventual prin interfața non-virtuală din bază  
    Am adaugat `void print(std::ostream& os)` si `virtual void printImpl(std::ostream& os)`  
    ##### g ✅) suprascris cc/op= pentru copieri/atribuiri corecte, copy and swap  
    ##### f ✅) dynamic_cast/std::dynamic_pointer_cast pentru downcast cu sens  
    In 'Restaurant' am adaugat functia 'void Restaurant::switchHUD(std::size_t index)'  
    ##### e ✅)smart pointers (recomandat, opțional)  
####3)excepții  
    ##### a ✅) ierarhie proprie cu baza std::exception sau derivată din std::exception; minim 3 clase pentru erori specifice distincte  
    `class GameException : public std::runtime_error`  
     Clase derivate:  
     `StationException`  
     `ActionException`  
     `ConfigException`  
     Fiecare clasă derivată adaugă un prefix specific mesajului de eroare, indicând clar categoria problemei.  
    ##### b ✅)clasele de excepții trebuie să trateze categorii de erori distincte (exemplu de erori echivalente: citire fișiere cu diverse extensii)  
    ##### c ✅)utilizare cu sens: de exemplu, throw în constructor (sau funcție care întoarce un obiect), try/catch în main  
####4✅)funcții și atribute static  
    Am adaugat clasa 'GameStats' care contine functii si atribute static  
####5✅)STL  
####6✅)cât mai multe const  
####7✅)funcții de nivel înalt, de eliminat cât mai mulți getters/setters/funcții low-level  
####8✅)minim 75-80% din codul propriu să fie C++  
####9✅)la sfârșit: commit separat cu adăugarea unei noi clase derivate fără a modifica restul codului, pe lângă cele 3 derivate deja adăugate din aceeași ierarhie  
noua derivată nu poate fi una existentă care a fost ștearsă și adăugată din nou  
noua derivată va fi integrată în codul existent (adică va fi folosită, nu adăugată doar ca să fie)  
    Am adaugat si implementat intr-un nou commit clasa derivata `Drinkstation`  
 ####10✅)tag de git pe commit cu toate bifele: de exemplu v0.2  
