# when you run ```docker run -d -p 18080:8080 plantuml/plantuml-server:tomcat```
# you can show the service after connecting http://mylife.better.com:18080 if plantuml server works well.
# http proxy  is  hostname : mylife.better.com    port : 18080
# ex)  http://mylife.better.com:18080/proxy?fmt=svg&
# ex)  http://mylife.better.com:18080/proxy?fmt=png&
myPlantumlServerProxy = 'http://tiger02.lge.com:18080/proxy?fmt=svg&'

# http path for your directory    ex)  'http://mylife.better.com/user/code/doxygen_perlmod_python/test-server/output/perlmod/test-1.puml'
mySrcHttp = 'http://tiger02.lge.com/cheoljoo.lee/code/doxygen_perlmod_python/test-server/output/perlmod'
