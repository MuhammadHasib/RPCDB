#!/usr/bin/env python
from ROOT import *
from array import array
import json
import datetime


gROOT.ProcessLine(".L RootTree.h+");
###########
json_data=open('test1.json')
data = json.load(json_data)
data2 = data['data']
###########

###########
f = TFile('tree_RPCWBM.root','RECREATE')
tree_ = TTree("tree",'RPC WBM tree')
fevent_ = RootTree()
fevent_.book(tree_);

###############
for i,data3 in enumerate(data2):
  xx=[]
  yy=[]
  name = "%s"%data3['name']
  #print "type(name) : " + type(name)
  #print "%s\n"%data3['name']
  #print "%s\n"%data3['data']
  for ii in data3['data']:
    fevent_.clear()
    fevent_.date_ =long(ii[0]) 
    fevent_.value_=float(ii[1])
    fevent_.name_.push_back(str(name))

    xx.append(int(ii[0]))
    yy.append(float(ii[1]))
    #print name + " , " + "%d"%ii[0] + ", " + "%f"%ii[1]
    #print name + " , " + datetime.datetime.fromtimestamp( int(ii[0])/1000 ).strftime('%Y-%m-%d %H:%M:%S') + " , " + "%f"%ii[1]
    tree_.Fill()
###################

f.Write()
f.Close()

