# coding: utf-8

from __future__ import absolute_import

from flask import json
from six import BytesIO

from swagger_server.models.application import Application  # noqa: E501
from swagger_server.test import BaseTestCase


class TestApplicationsController(BaseTestCase):
    """ApplicationsController integration test stubs"""

    def test_create_application(self):
        """Test case for create_application

        Метод создания заявки на издательство
        """
        body = Application()
        response = self.client.open(
            '/PONUGA20609_1/hw2/1.0.0/allApplications',
            method='POST',
            data=json.dumps(body),
            content_type='application/json')
        self.assert200(response,
                       'Response body is : ' + response.data.decode('utf-8'))

    def test_delete_application_by_id(self):
        """Test case for delete_application_by_id

        Метод удаления заявки на издательство по идентификатору
        """
        response = self.client.open(
            '/PONUGA20609_1/hw2/1.0.0/application/{application_id}'.format(application_id='application_id_example'),
            method='DELETE')
        self.assert200(response,
                       'Response body is : ' + response.data.decode('utf-8'))

    def test_get_all_applications(self):
        """Test case for get_all_applications

        Метод получение всех заявок на издательство
        """
        response = self.client.open(
            '/PONUGA20609_1/hw2/1.0.0/allApplications',
            method='GET')
        self.assert200(response,
                       'Response body is : ' + response.data.decode('utf-8'))

    def test_get_application_by_id(self):
        """Test case for get_application_by_id

        Метод получение заявки на издательство по идентификатору
        """
        response = self.client.open(
            '/PONUGA20609_1/hw2/1.0.0/application/{application_id}'.format(application_id='application_id_example'),
            method='GET')
        self.assert200(response,
                       'Response body is : ' + response.data.decode('utf-8'))

    def test_update_application_by_id(self):
        """Test case for update_application_by_id

        Метод обновления заявки на издательство по идентификатору
        """
        body = Application()
        response = self.client.open(
            '/PONUGA20609_1/hw2/1.0.0/application/{application_id}'.format(application_id='application_id_example'),
            method='PUT',
            data=json.dumps(body),
            content_type='application/json')
        self.assert200(response,
                       'Response body is : ' + response.data.decode('utf-8'))


if __name__ == '__main__':
    import unittest
    unittest.main()
