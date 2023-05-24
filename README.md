# fips-examples
FIPS 140 examples

# Notes

In us-east-2, pick Marketplace AMI at $0.10/hr 

ubuntu-pro-server/images/hvm-ssd/ubuntu-focal-20.04-amd64-pro-server-20230313
ami-0c2042215650076c5

Going for m5.large at $0.11 /hr

```
chmod 400 ~/.ssh/aws-ohio.pem
ssh ubuntu@ec2-3-21-163-89.us-east-2.compute.amazonaws.com
```

Then 

```
sudo apt-get update
sudo apt-get upgrade
sudo shutdown -r now
sudo apt-get install ubuntu-advantage-tools
sudo ua enable fips
sudo ua status
```

```
sudo apt-get install gcc


sudo apt install -y libssl1.1 libssl-dev openssl # fips-mode-bin

https://ubuntu.com/blog/how-to-develop-linux-applications-for-fips-on-ubuntu
```

that failed... Trying again with

```
ubuntu@ip-172-31-39-76:~$ sudo ua enable fips
One moment, checking your subscription first
FIPS cannot be enabled with Livepatch.
Disable Livepatch and proceed to enable FIPS? (y/N)
```

Chickening out and trying 

Trying the FIPS pro image:

