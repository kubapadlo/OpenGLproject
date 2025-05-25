# 🖼️ Potok grafiki

Potok grafiki to sekwencja kroków, które wykonuje GPU, aby przekształcić dane 3D w końcowy obraz 2D. Poniżej przedstawiono etapy programowalnego potoku graficznego (np. w OpenGL):

---

## 🔷 1. Dane wejściowe (Input)

To dane przesyłane z CPU do GPU:

- Wierzchołki (pozycje, kolory, normalne, współrzędne tekstur),
- Indeksy (np. do rysowania siatek trójkątów),
- Tekstury,
- Uniformy (stałe dane jak macierze `model`, `view`, `projection`).

👉 Buforowane w:
- `VBO` – Vertex Buffer Object,
- `VAO` – Vertex Array Object.

---

## 🔷 2. Vertex Shader (Shader Wierzchołków)

Pierwszy programowalny etap. Przetwarza każdy wierzchołek oddzielnie.

**Zadania:**

- Transformacje przestrzeni: lokalna → światowa → kamery → rzutowania,
- Obliczenie przekazywanych dalej atrybutów (kolor, UV itp.).

**Wynik:** współrzędne w NDC (*Normalized Device Coordinates*) i dane do interpolacji.

---

## 🔷 3. Primitive Assembly (Składanie Prymitywów)

Wierzchołki są łączone w **prymitywy**:  
➡️ trójkąty, linie, paski trójkątów itp. (`GL_TRIANGLES`, `GL_LINES`, ...)

---

## 🔷 4. Clipping (Obcinanie)

Trójkąty wykraczające poza obszar widzenia (tzw. *view frustum*) są częściowo lub całkowicie usuwane.

---

## 🔷 5. Rasterization (Rasteryzacja)

Prymitywy są przekształcane na siatkę pikseli.

**Zadania:**

- Określenie, które piksele są objęte prymitywem,
- Interpolacja danych z wierzchołków (kolor, UV itp.) dla każdego piksela.

---

## 🔷 6. Fragment Shader (Shader Fragmentów)

Program uruchamiany dla każdego fragmentu (kandydata na piksel).

**Zadania:**

- Obliczenie koloru fragmentu (np. oświetlenie, tekstura, cienie),
- Obsługa efektów: przezroczystość, światła, teksturowanie, shading.

---

## 🔷 7. Testy i operacje na ramce (Framebuffer Operations)

Przed zapisaniem piksela do obrazu:

- ✅ **Depth Test** – renderuj tylko najbliższy piksel,
- ✅ **Alpha Test / Blending** – przezroczystość,
- ✅ **Stencil Test** – operacje logiczne na masce,
- ✅ **Scissor Test** – rysowanie w określonym obszarze.

---

## 🔷 8. Zapis do Framebuffera

Ostateczne piksele są zapisywane do `framebuffer` i wyświetlane na ekranie.

---


