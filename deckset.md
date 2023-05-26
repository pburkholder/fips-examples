# 14 Problems with FIPS-140

---


## Bona Fides


---

# Opinions my own


---

* I vehemently welcome your critique

Although I work for the U.S. Government, my views
do not represent...

Further, I have no formal sway, so your opinion
can do nothing to aid or impede any business you
may have with the federal government

---

# Here's the list

1. FIPS bugs are nearly impossible to resolve
2. FIPS doesn't prevent stupid (3 examples)
   1. Using a NULL IV
   2. Rolling your own
   3. Stepping outside the garden
4. FIPS solves a 1990s problem (back then enc was rare, esoteric, now is ubquitious well-solved)
5. FIPS is a ceiling, not a floor
6. FIPS isn't in line with NIST recommendations
7. FIPS is an impediment to adopting encryption
8. FIPS leads to intolerable operational/security tradeoffs
9.  FIPS timelines are glacial
10. FIPS is incompatible with open-source software
11. FIPS is a nightmare on GoLang
12. FIPS is anti-competitive
13. FIPS provides minimal protection value (FedRAMP/MITRE)
14. FIPS doesn't prevent most SC-13-related issues
    1.  CWEs etc.
15. FIPS leads to surrogation bias
    1.  Ryan said that FIPS-140 leads
16. FIPS leads to silliness (e.g. FIPS TOTP)
17. FIPS compliance status is indeterminate
    1.  Even GSA IT can't attest to the FIPS status of AD/SecureAuth
18. FIPS is non-deterministic 
    1.  Why did ED25519 work on my FIPS box??
    2.  Why should I care?
19. FIPS, even when providing value, isn't the target 
20. FIPS is intolerably expensive
21. FIPS biases decision making 
    1.  prioritizing prevent over detection and response
---

## X. FIPS doesn't prevent stupid

* Demo with IVs (initialization vectors)

---
# What to do

* Encryption [1] is just software

---

# What do do

* Encryption [1] is ~just~ also software
* Embrace the SSDF and apply the same principles
* Code review, testing, training, sound practices, etc.
* In short, drop formal validation for FIPS 140 l1 and l2

---





---

