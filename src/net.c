#include "include.h"

#ifdef LANG_NETWORKING

#include <sys/socket.h>
#include <arpa/inet.h>
#include <stdbool.h>
#include <unistd.h>




size_t NetAddress (lang_t *lang) {
	struct sockaddr_in *addr = (struct sockaddr_in *) malloc (sizeof (struct sockaddr_in));

	if (!inet_aton ((char *) lang->update (lang), &addr->sin_addr))
		{ perror (NULL); return (size_t) NULL; }
	addr->sin_port = htons ((size_t) lang->update (lang));
	addr->sin_family = AF_INET;

	return (size_t) addr;
}


size_t NetBroadcast (lang_t *lang) {
	struct sockaddr_in *addr = (struct sockaddr_in *) malloc (sizeof (struct sockaddr_in));

	addr->sin_addr.s_addr = htonl (INADDR_BROADCAST);
	addr->sin_port = htons ((size_t) lang->update (lang));
	addr->sin_family = AF_INET;

	return (size_t) addr;
}

size_t NetSocket (void) { return socket (AF_INET, SOCK_DGRAM, IPPROTO_UDP); }

void NetSend (lang_t *lang) {
	size_t remote = (size_t) lang->update (lang);
	struct sockaddr_in *local = (struct sockaddr_in *) lang->update (lang);
	char *packet = (char *) lang->update (lang);
	bool broadcast = false;

	if (local->sin_addr.s_addr == htonl (INADDR_BROADCAST)) {
		broadcast = true;
		setsockopt (remote, SOL_SOCKET, SO_BROADCAST, &broadcast, sizeof (const size_t));
	}

	SYSTEM_CHECK (sendto (remote, packet, strlen (packet), (size_t) (size_t) NULL, (struct sockaddr *) local, sizeof (struct sockaddr)));
}

size_t NetBind (lang_t *lang) {
	size_t remote = (size_t) lang->update (lang);
	struct sockaddr_in local;

	local.sin_family = AF_INET;
	local.sin_port = htons ((size_t) lang->update (lang));
	local.sin_addr.s_addr = htonl (INADDR_ANY);

	SYSTEM_CHECK (bind (remote, (struct sockaddr *) &local, sizeof (struct sockaddr_in)));

	return remote;
}

char *NetReceive (lang_t *lang) {
	unsigned len = sizeof (struct sockaddr_in);
	size_t remote = (size_t) lang->update (lang);
	char *packet = (char *) malloc (4096 * sizeof (char));			/* Implement custom sized packets? */	

	SYSTEM_CHECK (recvfrom (remote, packet, 4096, '\0', (struct sockaddr *) NULL, &len));

	return lang->uniquestr (lang, packet);
}




#endif
