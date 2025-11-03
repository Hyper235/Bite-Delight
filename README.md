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
