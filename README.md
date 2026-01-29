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

1 ✅) separarea codului din clase în .h (sau .hpp) și .cpp  

2 ✅) moșteniri:  
a ✅) minim o clasă de bază și 3 clase derivate din aceeași ierarhie  
Clasă de bază: WorkStation  
Clase derivate:  
OrderStation  
GrillStation  
BuildStation  
ServeStation  

b ✅) ierarhia trebuie să fie cu bază proprie, nu derivată dintr-o clasă predefinită  
WorkStation nu derivă din clase predefinite (STL / SFML)  

c ✅) funcții virtuale (pure) apelate prin pointeri de bază din clasa care conține atributul de tip pointer de bază  
std::vector<std::unique_ptr<WorkStation>> stations; în clasa Restaurant  

d ✅) minim o funcție virtuală va fi specifică temei  
processAction([[maybe_unused]] ActionType action,
              [[maybe_unused]] Ingredient* ingredient,
              Order& order,
              Player& player)  

e ✅) constructori virtuali (clone)  
Am adăugat clasei WorkStation constructor virtual clone  

f ✅) afișare virtuală, interfață non-virtuală  
Am adăugat metodele print(std::ostream& os) și virtual printImpl(std::ostream& os)  

g ✅) apelarea constructorului din clasa de bază din constructori din derivate  
Toate clasele derivate apelează explicit constructorul WorkStation  

h ✅) clasă cu atribut de tip pointer la o clasă de bază cu derivate; apelare polimorfică  
Funcțiile virtuale sunt apelate prin pointer de bază, inclusiv prin interfața non-virtuală din bază  

i ✅) suprascris cc / operator= pentru copieri și atribuiri corecte, folosind copy and swap  

j ✅) dynamic_cast / std::dynamic_pointer_cast pentru downcast cu sens  
În clasa Restaurant am adăugat funcția void Restaurant::switchHUD(std::size_t index)  

k ✅) smart pointers  
Utilizare std::unique_ptr  

3 ✅) excepții  
a ✅) ierarhie proprie cu bază std::exception sau derivată din std::exception  
class GameException : public std::runtime_error  
Clase derivate:  
StationException  
ActionException  
ConfigException  
Fiecare clasă derivată adaugă un prefix specific mesajului de eroare  

b ✅) clasele de excepții tratează categorii distincte de erori  
StationException – erori ale stațiilor  
ActionException – acțiuni invalide  
ConfigException – erori de configurare  

c ✅) utilizare cu sens  
throw în constructori și funcții critice  
try / catch în main  

4 ✅) funcții și atribute static  
Am adăugat clasa GameStats care conține funcții și atribute static  

5 ✅) STL  
Utilizare structuri STL (vector, map, optional etc.)  

6 ✅) cât mai multe const  
Metodele care nu modifică starea sunt marcate const  

7 ✅) funcții de nivel înalt  
Eliminare getters / setters inutile  
Logică exprimată prin metode semantice  

8 ✅) minim 75–80% din codul propriu este C++  

9 ✅) extensibilitate – clasă derivată nouă  
Am adăugat și integrat clasa derivată DrinkStation  
Clasa a fost implementată într-un commit separat  

10 ✅) tag de git  
Tag aplicat pe commitul final: v0.2  

---
## Milestone 3

#### 1 ✅) Clasă și funcție șablon
Am adăugat o clasă șablon `Inventory<T>` pentru a gestiona colecții generice de obiecte. Aceasta este însoțită de o funcție șablon liberă (friend `operator<<`) pentru a afișa conținutul oricărui tip de inventar, demonstrând flexibilitatea template-urilor.

#### 2 ✅) Design Patterns
Am implementat 3 design patterns noi pentru a îmbunătăți arhitectura proiectului:
   **a) Observer Pattern:** A fost implementat pentru a decupla `Order` (Subiectul) de clasele care depind de starea sa, precum `Customer` și `GameStats` (Observatorii). Când o comandă este finalizată sau expiră, observatorii sunt notificați și își actualizează starea (ex: `Customer` devine `HAPPY`/`ANGRY`, `GameStats` actualizează rating-ul).
   
   **b) Static Factory Method Pattern:** A fost implementat în clasa `Customer` pentru a centraliza logica de creare a obiectelor. Constructorii relevanți au fost făcuți `privați`, iar acum crearea se face exclusiv prin `Customer::create(...)`. Acest lucru ascunde complexitatea generării unui client și permite extinderea ușoară pentru noi tipuri de clienți.
   
   **c) Strategy Pattern:** A fost implementat pentru a refactoriza calculul prețului în `Order::calc()`. Logica `if/else if` a fost înlocuită cu o familie de algoritmi de pricing (`EasyPricingStrategy`, `MediumPricingStrategy`, etc.), "injectați" în `Order` la creare. Acest lucru face sistemul de pricing mai flexibil și mai ușor de extins.

#### 3 ✅) Funcționalități noi și Testare
- **Sistem de Rating:** Am extins `GameStats` pentru a include un rating al restaurantului care crește sau scade în timp real, ca reacție la starea comenzilor, prin intermediul pattern-ului Observer.
- **Suită de Test:** Am creat în `main.cpp` o funcție `runObserverTest()` care demonstrează clar și izolat funcționalitatea noilor pattern-uri, testând atât cazul de succes (comandă finalizată), cât și cel de eșec (comandă expirată).
