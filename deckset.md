# 14 Problems with FIPS-140

---


## Bona Fides


---

## Opinions my own


^I vehemently welcome your critique
Although I work for the U.S. Government, my views
do not represent...
Further, I have no formal sway, so your opinion
can do nothing to aid or impede any business you
may have with the federal government

---

# FIPS solves a 1990s problem 

^ back then enc was rare, esoteric and was a USGov issue
there were no reliable standards and the market hadn't produced them
To get s
[NIST released FIPS 140-1](https://tsapps.nist.gov/publication/get_pdf.cfm?pub_id=917970) in January 1994
SSH: 1995, SSL 2.0 (first published version), 1995

# FIPS is superfluous in the 2020s

^ The private sector and open source 
have pretty much solved cryptographic algorithms. 

# FIPS isn't providing you the protection you think it as

^ FIPS provides minimal protection value (FedRAMP/MITRE)

# FIPS doesn't protect you (much)

^ FIPS is only about the algorithm

# FIPS takes forever  (long timelines)

# FIPS has been left behind by the world

^ * E.g. ED25519 for keys, ChaCha20-Poly1305 for TLS
^ (See Gary's Slack)

# FIPS has been left behind by NIST

^ Even NIST's own guidance regularly 
recommends algorithms that haven't 
yet made it into FIPS 
^ NIST’s FIPS-140 https://csrc.nist.gov site isn’t FIPS-140 compliant (offer chacha20-poly1305)


--- 

# FIPS is a lie / FIPS status can be hard to determine

17. FIPS compliance status is indeterminate
    1.  Even GSA IT can't attest to the FIPS status of AD/SecureAuth
^ Even GSA can't determine if their systems 
are 100% FIPS-compatible

# FIPS 



2. FIPS doesn't prevent stupid (demo)
3. 
   1. Using a NULL IV - demo ready
   2. Rolling your own - nodemo, but obvious
   3. Stepping outside the garden - e.g. omnibus installs

1. FIPS bugs are nearly impossible to track down
   1. Status: demo on EC2 fips

---

4. FIPS is a ceiling, not a floor

---

6. FIPS is an impediment to adopting encryption 

^The HTTPS-everywhere  .... held back by FIPS 
(This is a weak argument)

---

1. FIPS leads to intolerable operational/security tradeoffs
   1. Example AWS ALBs
   2. Still not GA (and details are under NDA)

2.  FIPS timelines are glacial

3.  FIPS is incompatible with open-source software
    1.  Can't test against it
    2.  Can't build for it
    3.  AWS doesn't support it for OSS databases (MySQL and Psql)


4.  FIPS is a nightmare on [GoLang](https://github.com/golang/go/issues/33281) and results in only one K8s distro for government. (see also: anti-competitive)


11. FIPS is anti-competitive


13. FIPS, even if providing value, isn't the target 

14. FIPS doesn't prevent most SC-13-related issues
    1.  CWEs etc.
^Although per the FedRAMP RAR, SC-28, SC-12,SC-13 are in play for transmission, and AC-17(2) (Remote Access), IA-5(1) authentication, CM-5(3) (digital signatures). See https://www.fedramp.gov/2022-01-04-updated-rar-templates/


15. FIPS leads to surrogation bias
    1.  Ryan said that FIPS-140 leads

16. FIPS leads to silliness 
    1.  (e.g. FIPS TOTP)

18. FIPS is non-deterministic/mysterious
    1.  Why did ED25519 work on my FIPS box??
    2.  Why should I care?


19. FIPS is intolerably expensive

20. FIPS isn't salvaged by OpenSSL 3.0

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


CWE Analysis

