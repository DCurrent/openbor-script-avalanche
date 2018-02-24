Bad Brother G2 (Formally ani0012)
Caskey, Damon V.ani0012
2008-xx-xx

Switch to Grabattack2 when attacking Bad Brother. Copied from Utunnel's in model script.

void bad_brother_g2()
{

	void self = getlocalvar("self");
	void target = getentityproperty(self, "opponent");
	
	if(target==NULL())
	{
		target = getentityproperty(self, "grabbing");
	}

	if(target!=NULL())
	{
		char tname = getentityproperty(target, "defaultname");
		if(tname == "Bad_Brother")
		{			
			changeentityproperty(self, "animation", openborconstant("ANI_GRABATTACK2"));
		}
	}
}
