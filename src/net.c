#include "lang.h"

#ifdef LANG_NET

#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>




size_t netAddress (lang_t *lang) {
	struct sockaddr_in *addr = (struct sockaddr_in *) malloc (sizeof (struct sockaddr_in));

	FAIL_IF_NULL (inet_aton ((char *) lang->update (lang), &addr->sin_addr));
	addr->sin_port = htons ( lang->update (lang));
	addr->sin_family = AF_INET;

	return (size_t) addr;
}


size_t netBroadcast (lang_t *lang) {
	struct sockaddr_in *addr = (struct sockaddr_in *) malloc (sizeof (struct sockaddr_in));

	addr->sin_addr.s_addr = htonl (INADDR_BROADCAST);
	addr->sin_port = htons ( lang->update (lang));
	addr->sin_family = AF_INET;

	return (size_t) addr;
}

size_t netSocket (void) { return socket (AF_INET, SOCK_DGRAM, IPPROTO_UDP); }


void netSend (lang_t *lang) {
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


size_t netBind (lang_t *lang) {
	unsigned length = sizeof (struct sockaddr_in);
	size_t remote = (size_t) lang->update (lang);
	struct sockaddr_in local;

	local.sin_family = AF_INET;
	local.sin_port = htons ( lang->update (lang));
	local.sin_addr.s_addr = htonl (INADDR_ANY);

	SYSTEM_CHECK (bind (remote, (struct sockaddr *) &local, length));

	return remote;
}


char *netReceive (lang_t *lang) {
	unsigned length = sizeof (struct sockaddr_in);
	size_t remote = (size_t) lang->update (lang);
	char packet[BUFF_SIZE] = "";			/* NOT OPTIMIZED TODO set end of string to NULL */
	
	SYSTEM_CHECK (recvfrom (remote, packet, BUFF_SIZE, '\0', (struct sockaddr *) NULL /*GET SENDER HERE*/, &length));

	return lang->string->store (lang->string, packet);
}


void netClose (lang_t *lang) { SYSTEM_CHECK (close (lang->update (lang))); }


#endif
