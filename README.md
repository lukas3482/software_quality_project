# Software Quality Project

**Autor:** Lukas Wolf

---

## Make-Targets

| Target | Was wird ausgeführt |
|--------|---------------------|
| `make build` | Baut das c-Projekt |
| `make test` | Führt die C-Unit-Tests aus |
| `make check` | Statische Code Analyse |
| `make clean` | Löscht den `build/`-Ordner und Python-Caches |
| `make install-deps` | Installiert Python-Abhängigkeiten via pip |
| `make all` | Führt `build`, `test` und `check` nacheinander aus |

---

## Lokales Bauen und Testen

### Voraussetzungen

- CMake ≥ 3.17
- C-Compiler (gcc oder clang)
- clang-tidy
- Python ≥ 3.10 mit pip

### C-Projekt bauen und testen

```bash
make build   
make test    
make check  
make clean
```

### Python-Tests ausführen

```bash
make install-deps   # Abhängigkeiten installieren (einmalig)
make test          
make check  
make clean
```

### Alles auf einmal

```bash
make all
```

test für die pr