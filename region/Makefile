all:
	echo "DoxyDocs.pm is used for this document"
	if [ ! -e mysetting.py ]; then cp ../src/mysetting_example.py mysetting.py; exit 4; fi
	perl doxy2py.pl
	python3 hpp2plantuml.py -i hpp/EnvironmentVariant.h -i hpp/IRegionManagerService.h -i hpp/IRegionManagerServiceType.h -i hpp/RegionCommand.h -i hpp/RegionExtBase.h -i hpp/RegionInputManager.h -i hpp/RegionManager.h -i hpp/RegionManagerService.h -o all.puml -j out.json
	# if we use -j option in hpp2plantuml  , parse_hpp2plantuml.py is useless.
	#python3 parse_hpp2plantuml.py --inpuml=all.puml --outjson=parse-out.json
	python3 sample-mako.py --infile=class.mako --service="Region Service"  --plantumlServerProxy="http://tiger02.lge.com:18080/proxy?fmt=svg"  --fileHttpUrl="http://tiger02.lge.com/cheoljoo.lee/code/doxygen_perlmod_python/region"

p:
	python3 parse_hpp2plantuml.py --inpuml=all.puml --outjson=parse-out.json
d:
	python3 hpp2plantuml.py -i hpp/EnvironmentVariant.h -i hpp/IRegionManagerService.h -i hpp/IRegionManagerServiceType.h -i hpp/RegionCommand.h -i hpp/RegionExtBase.h -i hpp/RegionInputManager.h -i hpp/RegionManager.h -i hpp/RegionManagerService.h -o all.puml -j out.json -d
a:
	python3 hpp2plantuml.py -i hpp/EnvironmentVariant.h -i hpp/IRegionManagerService.h -i hpp/IRegionManagerServiceType.h -i hpp/RegionCommand.h -i hpp/RegionExtBase.h -i hpp/RegionInputManager.h -i hpp/RegionManager.h -i hpp/RegionManagerService.h -o all.puml -j out.json
