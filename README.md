# Bite & Delight 🍔🍕🥤
##Milestone 0
### Descriere
Bite & Delight este un joc de tip Fast Food Tycoon, inspirat din celebra serie Papa’s Games. Jucătorul administrează un restaurant mixt de fast food, unde poate crea și vinde diverse produse – pizza, burgeri, snacks și băuturi – gestionând meniurile și comenzile clienților.

Proiectul este realizat în C++, cu accent pe programarea orientată pe obiecte (OOP) și poate fi extins ulterior cu interfață grafică sau funcționalități suplimentare.

##Milestone 1

1 ✅) definirea a minim 3-4 clase folosind compunere cu clasele definite de voi; moștenirile nu se iau în considerare aici
Am stabilit fundația proiectului prin crearea a patru clase esențiale pentru mecanica jocului:
   a) FoodItem (FoodItem.h / FoodItem.cpp) - Produs
   b) Order (Order.h / Order.cpp) - Comanda
   c) Player (Player.h / Player.cpp) - Jucator/Administrator
   d) Customer (Customer.h/ Customer.cpp) - Client
   
2 ✅)constructori de inițializare cu parametri pentru fiecare clasă
Am implementat constructori de inițializare cu parametru pentru toate cele patru clase. Aceștia asigură inițializarea corectă și completă a obiectelor la creare.
  a) FoodItem: Primește id, name, price, și type (pentru a defini un produs unic).
  b) Order: Primește id, nivelul de difficulty, maxDuration (durata maximă) și lista de FoodItem-uri (conținutul comenzii).
  c) Player: Primește name și balance (soldul inițial).
  d) Customer: Primeste name și Order sau, alternativ, meniul (std::vector<FoodItem>) din care își generează automat o comandă.
  
3 ✅)pentru o aceeași (singură) clasă: constructor de copiere, operator= de copiere, destructor
  a) Constructor de Copiere: Permite crearea unei copii independente a unui client existent. Am utilizat specificația = default (după modernizarea codului) pentru a permite compilatorului să gestioneze eficient copierea membrilor, inclusiv a obiectului compus Order.
  b) Operator de Atribuire (operator=): Permite atribuirea valorilor unui obiect Customer către un altul (c1 = c2), prevenind auto-atribuirea și asigurând copierea corectă, membru cu membru. Am ales = default (sau implementare manuală simplă) deoarece clasa nu folosește pointeri bruti.
  c)Destructor: Deși destructorul implicit (~Customer() = default;) ar fi suficient, l-am declarat explicit pentru a demonstra conștientizarea ciclului de viață al obiectului și am confirmat că acesta este apelat corect (vizibil în output-ul testului "Customer Left").
