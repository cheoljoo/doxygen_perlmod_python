# when you run ```docker run -d -p 18080:8080 plantuml/plantuml-server:tomcat```
# you can show the service after connecting http://mylife.better.com:18080 if plantuml server works well.
# http proxy  is  hostname : mylife.better.com    port : 18080
# ex)  http://mylife.better.com:18080/proxy?fmt=svg
# ex)  http://mylife.better.com:18080/proxy?fmt=png
myPlantumlServerProxy = 'http://mylife.better.com:18080/proxy?fmt=svg'

# http path for your directory    ex)  'http://mylife.better.com/user/code/doxygen_perlmod_python/test-server/output/perlmod/test-1.puml'
mySrcDirHttp = 'http://mylife.better.com/user/code/doxygen_perlmod_python/test-server/output/perlmod'

# whole link : http://mylife.better.com:18080/proxy?fmt=svg&src=http://mylife.better.com/user/code/doxygen_perlmod_python/test-server/output/perlmod/test-1.puml
